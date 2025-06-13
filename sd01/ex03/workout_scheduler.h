/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workout_scheduler.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:42:43 by igilani           #+#    #+#             */
/*   Updated: 2025/06/13 11:44:54 by igilani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKOUT_SCHEDULER_H
#define WORKOUT_SCHEDULER_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct UserData {
	char *username;        // Username of the user
	int age;              // Age of the user
	int fitness_level;    // Fitness level (1-5)
	int goal;             // Fitness goal (e.g., weight loss, muscle gain)
} UserData;

typedef struct WorkoutPlan {
	char *username;        // Username of the user
	int duration;          // Duration of the workout plan in days
	int daily_exercises[30]; // Array to hold daily exercises (up to 30 days)
	char *daily_tips[30];  // Array to hold daily tips (up to 30 days)
} WorkoutPlan;

// Returns a new UserData (mocked). Returns NULL on failure.
struct UserData *get_user_data(char *username);
// Build a base WorkoutPlan from raw user data. Returns NULL on failure.
struct WorkoutPlan *build_base_plan(struct UserData *data);
// Optionally refine an existing plan. Returns the same pointer (or a new one) or NULL on failure.
struct WorkoutPlan *refine_plan(struct WorkoutPlan *plan, struct UserData *data);
// Determine how many days the workout schedule should span. Returns positive int, or <=0 on failure.
int determine_duration(struct WorkoutPlan *plan);
// Assign daily exercises for the next day into the plan.
void assign_daily_exercises(struct WorkoutPlan *plan, int day);
// Assign daily tips for the next day into the plan.
void assign_daily_tips(struct WorkoutPlan *plan, int day);
// Free functions for cleanup.
void free_user_data(struct UserData *data);
void free_workout_plan(struct WorkoutPlan *plan);

struct WorkoutPlan *create_workout_schedule(char *username);

#endif