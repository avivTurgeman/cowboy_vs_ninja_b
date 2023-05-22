#include "doctest.h"

#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/Point.hpp"
#include "sources/Character.hpp"
#include "sources/Cowboy.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/OldNinja.hpp"
#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace ariel;


TEST_SUITE("Point class"){
    Point p1(0, 0);
    Point p2(1, 5);
    Point p3(-1, -5);
    Point p4(3, 9);
    Point p5(6, 6);
    Point p6(6, 0);
    
    TEST_CASE("distance method"){
        double dist1 = p1.distance(p6);
        double dist2 = p6.distance(p5);
        double dist3 = p1.distance(p5);

        CHECK_EQ(p1.distance(p2), p1.distance(p3));
        CHECK_EQ(2 * (p1.distance(p2)), p2.distance(p3));
        CHECK_EQ(p1.distance(p4), p4.distance(p1));
        CHECK_NE(dist1, dist3);
        CHECK_EQ((dist1 * dist1) + (dist2 * dist2), dist3 * dist3);
    }

    TEST_CASE("moveTowards method"){
        double dist = p3.distance(p5);
        Point m1 = Point::moveTowards(p1, p4, 100);
        Point m2 = Point::moveTowards(p3, p5, dist);
        bool b1 = ((m1.getX() == p4.getX()) && (m1.getY() == p4.getY()));
        bool b2 = ((m2.getX() == p5.getX()) && (m2.getY() == p5.getY()));


        CHECK(b1);
        CHECK(b2);
        CHECK_THROWS_AS(Point::moveTowards(p2, p3, -5), std::invalid_argument);
    }

    TEST_CASE("print method"){
        CHECK_EQ(p3.print(), "(-1,-5)");
        CHECK_EQ(Point::moveTowards(p1, p6, 5.5).print(), "(0, 5.5)");
    }
}

TEST_SUITE("Character class"){

    TEST_SUITE("Characters initialization"){

        TEST_CASE("Cowboy class"){
            Cowboy bill("Bill", Point(-5, 6));

            CHECK(bill.isAlive());
            CHECK(bill.hasboolets());
            CHECK_EQ(bill.getName(), "Bill");
            CHECK_EQ(bill.getLocation().distance(Point(0, 0)), Point(-5, 6).distance(Point(0, 0)));
        }

        TEST_SUITE("Ninja's classes"){

            TEST_CASE("YoungNinja class"){
                YoungNinja karate_kid1("Daniel_Laruso", Point(0, 0));

                CHECK(karate_kid1.isAlive());
                CHECK_EQ(karate_kid1.getName(), "Daniel_Laruso");
                CHECK_EQ(karate_kid1.getLocation().distance(Point(0, 0)), Point(0, 0).distance(Point(0, 0)));
            }

            TEST_CASE("TrainedNinja class"){
                TrainedNinja karate_kid3("Daniel_Laruso", Point(5, 5));

                CHECK(karate_kid3.isAlive());
                CHECK_EQ(karate_kid3.getName(), "Daniel_Laruso");
                CHECK_EQ(karate_kid3.getLocation().distance(Point(0, 0)), Point(5, 5).distance(Point(0, 0)));
            }

            TEST_CASE("OldNinja class"){
                OldNinja ninja("Jacky_Chan", Point(10, 10));

                CHECK(ninja.isAlive());
                CHECK_EQ(ninja.getName(), "Jacky_Chan");
                CHECK_EQ(ninja.getLocation().distance(Point(0, 0)), Point(10, 10).distance(Point(0, 0)));
            }
        }
    }

    TEST_SUITE("Characters methods"){
        
        TEST_CASE("Cowboy methods"){
            Cowboy *bill = new Cowboy("Bill", Point(1, 5));
            Cowboy *bob = new Cowboy("Bob", Point(4, 5));
            TrainedNinja *daniel = new TrainedNinja("Daniel Laruso", Point(1000000, 5));

            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 6; j++){
                    CHECK_NOTHROW(bob->shoot(daniel));
                }
                CHECK_NOTHROW(bob->reload());
            }
            CHECK_FALSE(daniel->isAlive());

            CHECK_EQ(bill->distance(bob), 3);
            CHECK_EQ(bill->distance(daniel), 9999999);

            for(int i = 0; i < 6; i++){
                CHECK_NOTHROW(bob->shoot(bill));
            }
            CHECK(bill->isAlive());
            CHECK_FALSE(bob->hasboolets());
            CHECK_NOTHROW(bob->reload());
            CHECK(bob->hasboolets());
            for(int i = 0; i < 5; i++){
                CHECK_NOTHROW(bob->shoot(bill));
            }
            CHECK_FALSE(bill->isAlive());

            CHECK_EQ(bill->print(), "C(Bill)");

            CHECK_THROWS_AS(bill->shoot(bob), std::runtime_error); // bill is dead
            CHECK_THROWS_AS(bill->reload(), std::runtime_error); 
            CHECK_THROWS_AS(bob->shoot(bob), std::runtime_error); // no suicide
            CHECK(bob->hasboolets());
            CHECK_NOTHROW(bob->reload());

            CHECK_THROWS_AS(bob->hit(-5), std::runtime_error);
            CHECK_THROWS_AS(bill->hit(5), std::runtime_error); // bill is already dead

            delete bill;
            delete bob;
            delete daniel;
        }

        TEST_CASE("Ninja's methods"){
            YoungNinja *johnny = new YoungNinja("Johnny Lawrence", Point(0,10));
            TrainedNinja *daniel = new TrainedNinja("Daniel Laruso", Point(0, 14.8));
            OldNinja *miyagi = new OldNinja("Mr. Miyagi", Point(0,19.3));
            Cowboy *bill = new Cowboy("Bill", Point(0,10.4));

            // no suicides
            CHECK_THROWS_AS(johnny->slash(johnny), std::runtime_error);
            CHECK_THROWS_AS(daniel->slash(daniel), std::runtime_error);
            CHECK_THROWS_AS(miyagi->slash(miyagi), std::runtime_error);
            
            //hit with negative number
            CHECK_THROWS_AS(johnny->hit(-6), std::runtime_error);
            CHECK_THROWS_AS(daniel->hit(-6), std::runtime_error);
            CHECK_THROWS_AS(miyagi->hit(-6), std::runtime_error);

            for(int i = 0; i < 3; i++){
                CHECK_NOTHROW(daniel->slash(johnny));
            }
            
            CHECK(johnny->isAlive());

            CHECK(daniel->distance(johnny) >= 1);
            CHECK_NOTHROW(daniel->move(johnny));
            CHECK(daniel->distance(johnny) < 1);

            for(int i = 0; i < 3; i++){
                CHECK_NOTHROW(daniel->slash(johnny));
            }
            
            CHECK_FALSE(johnny->isAlive());
            CHECK_THROWS_AS(daniel->move(johnny), std::runtime_error); // johnny is dead
            CHECK_EQ(johnny->print(), "N(Johnny Lawrence)");

            for(int i = 0; i < 3; i++){
                CHECK_NOTHROW(miyagi->slash(bill));
            }
            
            CHECK(bill->isAlive());

            CHECK(miyagi->distance(bill) >= 1);
            CHECK_NOTHROW(miyagi->move(bill));
            CHECK(miyagi->distance(bill) < 1);

            for(int i = 0; i < 3; i++){
                CHECK_NOTHROW(miyagi->slash(bill));
            }
            
            CHECK_FALSE(bill->isAlive());

            delete johnny;
            delete daniel;
            delete miyagi;
            delete bill;
        }
    }
}

TEST_SUITE("Team class"){

    TEST_CASE("Team Initialization"){
        YoungNinja *johnny = new YoungNinja("Johnny Lawrence", Point(0,10));
        TrainedNinja *daniel = new TrainedNinja("Daniel Laruso", Point(0, 14.8));
        
        Team team1(daniel);
        CHECK_EQ(team1.stillAlive(), 1);

        Team2 team2(johnny);
        CHECK_EQ(team2.stillAlive(), 1);
    }

    TEST_CASE("Team methods"){

        YoungNinja *johnny = new YoungNinja("Johnny Lawrence", Point(0,10));
        TrainedNinja *daniel = new TrainedNinja("Daniel Laruso", Point(0, 14.8));
        OldNinja *miyagi = new OldNinja("Mr. Miyagi", Point(0,43));
        Cowboy *bill = new Cowboy("Bill", Point(0,10.4));

        Team miyagi_do(miyagi);
        CHECK_NOTHROW(miyagi_do.add(daniel));
        CHECK_EQ(miyagi_do.stillAlive(), 2);

        Team2 cobra_kai(johnny);
        CHECK_NOTHROW(cobra_kai.add(bill));
        CHECK_EQ(cobra_kai.stillAlive(), 2);
        CHECK_THROWS_AS(cobra_kai.add(daniel), std::invalid_argument);

        for(int i = 1; i < 9; i++){
            string name = "champion" + std::to_string(i);
            CHECK_NOTHROW(miyagi_do.add(new Cowboy(name, Point(0, i + 20))));
        }
        CHECK_THROWS_AS(miyagi_do.add(new Cowboy("cowboy", Point(0,10))), std::invalid_argument);
    
        // No friendly fire
        CHECK_THROWS_AS(miyagi_do.attack(&miyagi_do), std::invalid_argument);
        CHECK_THROWS_AS(cobra_kai.attack(&cobra_kai), std::invalid_argument);
        
        //team leader changes and game continue on
        johnny->hit(120);
        miyagi->hit(150);
        CHECK_NOTHROW(cobra_kai.attack(&miyagi_do));
        CHECK_NOTHROW(miyagi_do.attack(&cobra_kai));


        OldNinja *splinter = new OldNinja("Master Splinter",Point(15,7));
        TrainedNinja *leo = new TrainedNinja("Leonardo",Point(14,6));
        TrainedNinja *dona = new TrainedNinja("Donatello",Point(16,8));
        TrainedNinja *mikey = new TrainedNinja("Michelangelo",Point(16,6));
        TrainedNinja *rafa = new TrainedNinja("Rafael",Point(14,8));

        Team Ninja_Turtles(splinter);
        CHECK_NOTHROW(Ninja_Turtles.add(leo));
        CHECK_NOTHROW(Ninja_Turtles.add(dona));
        CHECK_NOTHROW(Ninja_Turtles.add(rafa));
        CHECK_NOTHROW(Ninja_Turtles.add(mikey));

        Cowboy *c1 = new Cowboy("cowboy1", Point(25,0));
        Team cowboys(c1);
        for(int i = 2; i < 11; i++){
            string name = "cowboy" + std::to_string(i);
            CHECK_NOTHROW(cowboys.add(new Cowboy(name, Point(i + 25, 0))));
        }

        const std::chrono::seconds duration(15);
        auto startTime = std::chrono::steady_clock::now();

        while ((std::chrono::steady_clock::now() - startTime < duration) || 
                    (Ninja_Turtles.stillAlive() && cowboys.stillAlive())){

            CHECK_NOTHROW(Ninja_Turtles.attack(&cowboys));
            CHECK_NOTHROW(cowboys.attack(&Ninja_Turtles));
        }

        bool end_game = !(Ninja_Turtles.stillAlive()) || !(cowboys.stillAlive());
        CHECK(end_game);
    }

}
