/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_organizer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:20:46 by igilani           #+#    #+#             */
/*   Updated: 2025/06/13 11:34:44 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUSIC_ORGANIZER_H
#define MUSIC_ORGANIZER_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct MusicFile {
	char *filename;        // Name of the music file
	char *artist;         // Artist name
	char *album;          // Album name
	char *genre;          // Genre of the music
	int duration;         // Duration in seconds
} MusicFile;

typedef struct MusicLibrary {
	MusicFile **songs;    // Array of pointers to MusicFile structures
	size_t song_count;    // Number of songs in the library
} MusicLibrary;

// Creates and returns a new music library. Returns NULL on fail
struct MusicLibrary *create_music_library();
// Scans a directory for music files. Returns a NULL terminated array of filenames.
const char **scan_directory(const char *directory_path);
// Processes a single music file. Returns a data structure representing the processed file.
struct MusicFile *process_music_file(const char *directory_path, const char *filename);
// Updates the music library with the processed music file information.
void update_music_library(struct MusicLibrary *library, struct MusicFile *song);

struct MusicLibrary *organize_music_library(const char *directory_path);
void free_all(struct MusicLibrary *library, struct MusicFile *song);

#endif