// Author: Shengrui Zhang
// Date Created: 09/16/17

/* Description:
   Input: The amount of gold user desired to spend
   Output: Amount of health and armor to buy
		   effective health score 
*/

/* League of Legends:

 This program takes the user inputs and calculate the optimal amount of health and armor to buy for the given amount of gold
 
 
 */
 
 
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

//int i = 0; // Loop variable

int gold = 0;

int armor = 0; // armor
int tar_armor = 0; // optimal amount of armor
int armor_max = 0; // max possible amount of armor

int health = 0; // health
int tar_health = 0; // optimal amount of health

double effec_HP = 0.0; // effective health
double tar_effec_HP = 0.0; // optimal effective health


int main(void) {
	
//	while (1) {

		printf("How much gold do you wish to spend? "); // Get the gold :)
		scanf("%d", &gold);

		armor_max = (gold / 18); // find the maximum possible gold can be purchased


		while (armor <= armor_max) {    // start the loop, loop until armor_max is reached

			health = (gold / 2); // finding the health for eahc given armor amount
			health = health - (9 * armor);

			//printf("health:%lf\n", health); // test

			effec_HP = health * (100 + armor); // finding effective health
			effec_HP = effec_HP / 100;

			if (((effec_HP - tar_effec_HP) > 0.0001)) {

				tar_effec_HP = effec_HP; // store the new values
				tar_armor = armor;
				tar_health = health;
			}

			armor++; // update armor

			//printf("effhealth:%.3lf\n", effec_HP); // test

			//goto end; // test
		}
		
		gold = (2 * tar_health) + (18 * tar_armor);
		
		printf("For %d gold you should buy %d Health, and %d Armor for an effective health score of %.3lf \n", gold, tar_health, tar_armor, tar_effec_HP);

	//end:  // target to end the program
//	}

	return 0;
}