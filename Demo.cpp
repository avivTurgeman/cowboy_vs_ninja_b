/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <random>
#include <chrono>

#define MAX_TEAM 10
using namespace std;

#include "sources/SmartTeam.hpp"
#include "sources/Team2.hpp"

using namespace ariel;
//<--------------------Helper Functions-------------------->
//https://www.geeksforgeeks.org/generate-a-random-float-number-in-cpp/

double random_float(double min = -100, double max = 100) {
   std::default_random_engine generator(static_cast<unsigned long>(std::chrono::system_clock::now().time_since_epoch().count()));
   std::uniform_real_distribution<double> distribution(min, max);

   return distribution(generator);
}

auto create_yninja = [](double x = random_float(), double y = random_float()) {
   return new YoungNinja{"Bob", Point{x, y}};
};

auto create_tninja = [](double x = random_float(), double y = random_float()) {
   return new TrainedNinja{"Bob", Point{x, y}};
};
 
auto create_oninja = [](double x = random_float(), double y = random_float()) {
   return new OldNinja{"Bob", Point{x, y}};
};

auto create_cowboy = [](double x = random_float(), double y = random_float()) {
   return new Cowboy{"Bob", Point{x, y}};
};

auto random_char(double x = random_float(), double y = random_float()) -> Character * {
   int flag = static_cast<int>(random_float()) % 4;

   if (flag == 0) return create_cowboy(x, y);

   if (flag == 1) return create_yninja(x, y);

   if (flag == 2) return create_tninja(x, y);

   return create_oninja(x, y);
}

auto simulate_battle = [](Team &team, Team &team2) -> int {
   int i = 0;
   while (team.stillAlive() && team2.stillAlive()) {
      if (i % 2 == 0) {
         team.attack(&team2);
      } else {
         team2.attack(&team);
      }
      i++;
   }
   if(team.stillAlive()){
      return 1;
   }
   return 2;
};


int main() {

   cout << "\033[1;34m" << "\n======== Team VS Team ========\n" << "\033[0m";
   
   size_t countdown1;
   int team1_1_wins = 0;
   int team2_1_wins = 0;
   
   for(countdown1 = 10000; countdown1 > 0; countdown1--){
      Team team{random_char()};
      Team team2{random_char()};

      for (int i = 0; i < MAX_TEAM - 1; i++) {
            team.add(random_char());
            team2.add(random_char());
      }

      int winner = simulate_battle(team, team2);
      if(winner == 1){
         team1_1_wins++;
      }
      else{
         team2_1_wins++;
      }
   }

   double team1_1_rating = static_cast<double>(team1_1_wins) / 10000 * 100;
   double team2_1_rating = static_cast<double>(team2_1_wins) / 10000 * 100;

   cout << "first attacker won: " << "\033[1;32m" << team1_1_rating << "%" << "\033[0m" << " of the times\n";
   cout << "second attacker won: " << "\033[1;32m" << team2_1_rating << "%" << "\033[0m" << " of the times\n";

   cout << "\033[1;34m" << "\n======== Team VS Team2 ========\n" << "\033[0m";
   
   size_t countdown2;
   int team1_2_wins = 0;
   int team2_2_wins = 0;
   
   for(countdown2 = 10000; countdown2 > 0; countdown2--){
      Team team{random_char()};
      Team2 team2{random_char()};

      for (int i = 0; i < MAX_TEAM - 1; i++) {
            team.add(random_char());
            team2.add(random_char());
      }

      int winner = simulate_battle(team, team2);
      if(winner == 1){
         team1_2_wins++;
      }
      else{
         team2_2_wins++;
      }
   }

   double team1_2_rating = static_cast<double>(team1_2_wins) / 10000 * 100;
   double team2_2_rating = static_cast<double>(team2_2_wins) / 10000 * 100;

   cout << "first attacker(Team) won: " << "\033[1;32m" << team1_2_rating << "%" << "\033[0m" << " of the times\n";
   cout << "second attacker(Team2) won: " << "\033[1;32m" << team2_2_rating << "%" << "\033[0m" << " of the times\n";

   
   cout << "\033[1;34m" << "\n======== Team2 VS Team ========\n" << "\033[0m";
   
   size_t countdown3;
   int team1_3_wins = 0;
   int team2_3_wins = 0;
   
   for(countdown3 = 10000; countdown3 > 0; countdown3--){
      Team team{random_char()};
      Team2 team2{random_char()};

      for (int i = 0; i < MAX_TEAM - 1; i++) {
            team.add(random_char());
            team2.add(random_char());
      }

      int winner = simulate_battle(team2, team);
      if(winner == 1){
         team1_3_wins++;
      }
      else{
         team2_3_wins++;
      }
   }

   double team1_3_rating = static_cast<double>(team1_3_wins) / 10000 * 100;
   double team2_3_rating = static_cast<double>(team2_3_wins) / 10000 * 100;

   cout << "first attacker(Team2) won: " << "\033[1;32m" << team1_3_rating << "%" << "\033[0m" << " of the times\n";
   cout << "second attacker(Team) won: " << "\033[1;32m" << team2_3_rating << "%" << "\033[0m" << " of the times\n";


   cout << "\033[1;34m" << "\n======== Team2 VS Team2 ========\n" << "\033[0m";
   
   size_t countdown6;
   int team1_6_wins = 0;
   int team2_6_wins = 0;
   
   for(countdown6 = 10000; countdown6 > 0; countdown6--){
      Team2 team{random_char()};
      Team2 team2{random_char()};

      for (int i = 0; i < MAX_TEAM - 1; i++) {
            team.add(random_char());
            team2.add(random_char());
      }

      int winner = simulate_battle(team, team2);
      if(winner == 1){
         team1_6_wins++;
      }
      else{
         team2_6_wins++;
      }
   }

   double team1_6_rating = static_cast<double>(team1_6_wins) / 10000 * 100;
   double team2_6_rating = static_cast<double>(team2_6_wins) / 10000 * 100;

   cout << "first attacker(Team2) won: " << "\033[1;32m" << team1_6_rating << "%" << "\033[0m" << " of the times\n";
   cout << "second attacker(Team2) won: " << "\033[1;32m" << team2_6_rating << "%" << "\033[0m" << " of the times\n";   


   cout << "\033[1;34m" << "\n======== Team VS SmartTeam ========\n" << "\033[0m";
   
   size_t countdown4;
   int team1_4_wins = 0;
   int team2_4_wins = 0;
   
   for(countdown4 = 10000; countdown4 > 0; countdown4--){
      Team team{random_char()};
      SmartTeam team2{random_char()};

      for (int i = 0; i < MAX_TEAM - 1; i++) {
            team.add(random_char());
            team2.add(random_char());
      }

      int winner = simulate_battle(team, team2);
      if(winner == 1){
         team1_4_wins++;
      }
      else{
         team2_4_wins++;
      }
   }

   double team1_4_rating = static_cast<double>(team1_4_wins) / 10000 * 100;
   double team2_4_rating = static_cast<double>(team2_4_wins) / 10000 * 100;

   cout << "first attacker(Team) won: " << "\033[1;32m" << team1_4_rating << "%" << "\033[0m" << " of the times\n";
   cout << "second attacker(SmartTeam) won: " << "\033[1;32m" << team2_4_rating << "%" << "\033[0m" << " of the times\n";


   cout << "\033[1;34m" << "\n======== SmartTeam VS Team ========\n" << "\033[0m";
   
   size_t countdown5;
   int team1_5_wins = 0;
   int team2_5_wins = 0;
   
   for(countdown5 = 10000; countdown5 > 0; countdown5--){
      Team team{random_char()};
      SmartTeam team2{random_char()};

      for (int i = 0; i < MAX_TEAM - 1; i++) {
            team.add(random_char());
            team2.add(random_char());
      }

      int winner = simulate_battle(team2, team);
      if(winner == 1){
         team1_5_wins++;
      }
      else{
         team2_5_wins++;
      }
   }

   double team1_5_rating = static_cast<double>(team1_5_wins) / 10000 * 100;
   double team2_5_rating = static_cast<double>(team2_5_wins) / 10000 * 100;

   cout << "first attacker(SmartTeam) won: " << "\033[1;32m" << team1_5_rating << "%" << "\033[0m" << " of the times\n";
   cout << "second attacker(Team) won: " << "\033[1;32m" << team2_5_rating << "%" << "\033[0m" << " of the times\n";



   cout << "\033[1;34m" << "\n======== Team2 VS SmartTeam ========\n" << "\033[0m";
   
   size_t countdown7;
   int team1_7_wins = 0;
   int team2_7_wins = 0;
   
   for(countdown7 = 10000; countdown7 > 0; countdown7--){
      Team2 team{random_char()};
      SmartTeam team2{random_char()};

      for (int i = 0; i < MAX_TEAM - 1; i++) {
            team.add(random_char());
            team2.add(random_char());
      }

      int winner = simulate_battle(team, team2);
      if(winner == 1){
         team1_7_wins++;
      }
      else{
         team2_7_wins++;
      }
   }

   double team1_7_rating = static_cast<double>(team1_7_wins) / 10000 * 100;
   double team2_7_rating = static_cast<double>(team2_7_wins) / 10000 * 100;

   cout << "first attacker(Team2) won: " << "\033[1;32m" << team1_7_rating << "%" << "\033[0m" << " of the times\n";
   cout << "second attacker(SmartTeam) won: " << "\033[1;32m" << team2_7_rating << "%" << "\033[0m" << " of the times\n";   


   cout << "\033[1;34m" << "\n======== SmartTeam VS Team2 ========\n" << "\033[0m";
   
   size_t countdown8;
   int team1_8_wins = 0;
   int team2_8_wins = 0;
   
   for(countdown8 = 10000; countdown8 > 0; countdown8--){
      SmartTeam team{random_char()};
      Team2 team2{random_char()};

      for (int i = 0; i < MAX_TEAM - 1; i++) {
            team.add(random_char());
            team2.add(random_char());
      }

      int winner = simulate_battle(team, team2);
      if(winner == 1){
         team1_8_wins++;
      }
      else{
         team2_8_wins++;
      }
   }

   double team1_8_rating = static_cast<double>(team1_8_wins) / 10000 * 100;
   double team2_8_rating = static_cast<double>(team2_8_wins) / 10000 * 100;

   cout << "first attacker(SmartTeam) won: " << "\033[1;32m" << team1_8_rating << "%" << "\033[0m" << " of the times\n";
   cout << "second attacker(Team2) won: " << "\033[1;32m" << team2_8_rating << "%" << "\033[0m" << " of the times\n";   


   cout << "\033[1;34m" << "\n======== SmartTeam VS SmartTeam ========\n" << "\033[0m";
   
   size_t countdown9;
   int team1_9_wins = 0;
   int team2_9_wins = 0;
   
   for(countdown9 = 10000; countdown9 > 0; countdown9--){
      SmartTeam team{random_char()};
      SmartTeam team2{random_char()};

      for (int i = 0; i < MAX_TEAM - 1; i++) {
            team.add(random_char());
            team2.add(random_char());
      }

      int winner = simulate_battle(team, team2);
      if(winner == 1){
         team1_9_wins++;
      }
      else{
         team2_9_wins++;
      }
   }

   double team1_9_rating = static_cast<double>(team1_9_wins) / 10000 * 100;
   double team2_9_rating = static_cast<double>(team2_9_wins) / 10000 * 100;

   cout << "first attacker(SmartTeam) won: " << "\033[1;32m" << team1_9_rating << "%" << "\033[0m" << " of the times\n";
   cout << "second attacker(SmartTeam) won: " << "\033[1;32m" << team2_9_rating << "%" << "\033[0m" << " of the times\n";   


   cout << endl;
}
