/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_organizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:20:48 by igilani           #+#    #+#             */
/*   Updated: 2025/06/13 11:42:35 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "music_organizer.h"

void free_all(struct MusicLibrary *library)
{
	if (library)
	{
		for (size_t i = 0; i < library->song_count; i++)
		{
			if (library->songs[i]) {
				if (library->songs[i]->filename) free(library->songs[i]->filename);
				if (library->songs[i]->artist) free(library->songs[i]->artist);
				if (library->songs[i]->album) free(library->songs[i]->album);
				if (library->songs[i]->genre) free(library->songs[i]->genre);
				free(library->songs[i]);
			}
		}
		free(library->songs);
		free(library);
	}
}

struct MusicLibrary *organize_music_library(const char *directory_path)
{
	struct MusicLibrary *library = create_music_library();
	if (!library)
		return NULL;

	const char **filenames = scan_directory(directory_path);
	if (!filenames)
	{
		free_all(library);
		return NULL;
	}
	
	for (size_t i = 0; filenames[i] != NULL; i++)
	{
		struct MusicFile *song = process_music_file(directory_path, filenames[i]);
		if (song)
			update_music_library(library, song);
	}

	free(filenames);
	return library;
}