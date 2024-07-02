//******************
//
// scls_demo_snake.h
//
//******************
// Presentation :
//
// SCLS is a project containing base functions for C++.
// It can also be use in any projects.
//
// The "Demo" part is a part full of demonstrations for SCLS.
//
// This file contains a little snake game made with SCLS.
//
//******************
//
// License (GPL V3.0) :
//
// Copyright (C) 2024 by Aster System, Inc. <https://aster-system.github.io/aster-system/>
// This file is part of SCLS.
// SCLS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// SCLS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with SCLS. If not, see <https://www.gnu.org/licenses/>.
//

#ifndef SCLS_DEMO_SNAKE
#define SCLS_DEMO_SNAKE

// Include SCLS library
#include "../../../scls-3d-margaret/headers/scls_3d_engine.h"

// Using of the "scls" namespace to simplify the programmation
namespace scls {
    namespace demo {
        //*********
        //
        // The Snake_Total class
        //
        //*********

        class Snake_Total {
            // Class representating a total snake
        public:

            //*********
            //
            // Snake_Total mains members
            //
            //*********

            // Snake_Total constructor
            Snake_Total(Window& window, std::string name);

            //*********
            //
            // Snake_Total gameplay members
            //
            //*********

            // Kill the snake
            inline void kill() {a_dead = true;};

            // Getters and setters
            inline bool is_dead() const {return a_dead;};
            inline char last_move() const {return a_last_move;};
            inline double last_move_time() const {return a_last_move_time;};
            inline void reset_last_move_time() {a_last_move_time = 0;};
            inline void set_last_move(char new_last_move) {a_last_move = new_last_move;};
            inline void set_last_move_time(double new_last_move_time) {a_last_move_time = new_last_move_time;};
            inline void set_x(unsigned short new_x) {a_x = new_x;};
            inline void set_y(unsigned short new_y) {a_y = new_y;};
            inline unsigned short speed() const {return a_speed;};
            inline unsigned short x() const {return a_x;};
            inline unsigned short y() const {return a_y;};

            //*********
            //
            // Snake_Total GUI attributes
            //
            //*********

            // Returns the number of pieces of snake for this Snake
            unsigned int pieces_number() const {return a_pieces_x.size();};

            // Getters and setters
            inline std::vector<unsigned short>& pieces_x() {return a_pieces_x;};
            inline std::vector<unsigned short>& pieces_y() {return a_pieces_y;};

        private:

            //*********
            //
            // Snake_Total gameplay attributes
            //
            //*********

            // If the sneak is dead or not
            bool a_dead = false;
            // Last direction of the move of the snake
            char a_last_move = -1;
            // Time of the last move
            double a_last_move_time = 0;
            // Speed of the snake, in case per second
            unsigned short a_speed = 10;
            // X position of the snake
            unsigned short a_x = 0;
            // Y position of the snake
            unsigned short a_y = 0;

            //*********
            //
            // Snake_Total GUI attributes
            //
            //*********

            // Name of the snake
            std::string a_name = "";
            // X position of each pieces
            std::vector<unsigned short> a_pieces_x = std::vector<unsigned short>();
            // Y position of each pieces
            std::vector<unsigned short> a_pieces_y = std::vector<unsigned short>();
            // Window struct of the game
            Window& a_window;
        };

        //*********
        //
        // The Snake_Object and Snake_Piece class
        //
        //*********

        class Snake_Object : public GUI_Object {
            // Class representating an object in the Snake
        public:

            //*********
            //
            // Snake_Object mains members
            //
            //*********

            // Snake_Object constructor
            Snake_Object(Window& window, std::string name, GUI_Object* parent);

            // Getters and setters
            inline void set_type(const std::string& new_type) {a_type = new_type;};
            inline void set_x_in_cases(unsigned int new_x_in_cases) {a_x_in_cases = new_x_in_cases;};
            inline void set_y_in_cases(unsigned int new_y_in_cases) {a_y_in_cases = new_y_in_cases;};
            inline std::string type() const {return a_type;};
            inline unsigned int x_in_cases() const {return a_x_in_cases;};
            inline unsigned int y_in_cases() const {return a_y_in_cases;};

        private:

            //*********
            //
            // Snake_Object mains attributes
            //
            //*********

            // Type of the object
            std::string a_type = "";
            // X pos of the object in cases
            unsigned int a_x_in_cases = 0;
            // Y pos of the object in cases
            unsigned int a_y_in_cases = 0;
        };

        class Snake_Piece : public Snake_Object {
            // Class representating a piece of snake
        public:

            //*********
            //
            // Snake_Piece mains members
            //
            //*********

            // Snake_Piece constructor
            Snake_Piece(Window& window, std::string name, GUI_Object* parent);
        };

        //*********
        //
        // The Snake class
        //
        //*********

        class Snake : public Window {
            // Class representating the window for the Snake game
        public:

            //*********
            //
            // Snake mains members
            //
            //*********

            // Snake constructor
            Snake(int window_width, int window_height, std::string exec_path);

            //*********
            //
            // Snake Gameplay members
            //
            //*********

            // Deletes an object in the game
            void delete_object(Snake_Object* object_to_delete);
            // Kill a snake
            void kill_snake(Snake_Total &snake);
            // Returns the object at a position in the game
            Snake_Object* object_at(unsigned short x, unsigned short y);
            // Reset the game
            void reset_game();
            // Update the Snake
            virtual void update();
            // Update the objects
            virtual void update_objects();
            // Update the score according to a snake
            void update_score(Snake_Total &snake);
            // Update the number of snake pieces
            void update_snake_pieces();
            // Update the loaded snakes
            void update_snakes();

            //*********
            //
            // Snake GUI members
            //
            //*********

            // Calculate the positions of the GUI
            void calculate_GUI_positions();
            // Move a piece of snake at its position
            void move_snake(Snake_Total);
            // Move a piece of snake at a certains case
            void move_object(Snake_Object* object, unsigned int case_x, unsigned int case_y);
            // Create the background image of the playground part
            std::shared_ptr<Image> playground_image();

        private:

            //*********
            //
            // Snake gampelay attributes
            //
            //*********

            // Loaded snakes in the game
            std::vector<std::unique_ptr<Snake_Total>> a_loaded_snakes = std::vector<std::unique_ptr<Snake_Total>>();

            // Height of the playground in scale
            unsigned short a_height_in_cases = 15;
            // Width of the playground in scale
            unsigned short a_width_in_cases = 15;

            //*********
            //
            // Snake GUI attributes
            //
            //*********

            // Height of each case
            std::vector<long long> a_cases_height = std::vector<long long>();
            // Width of each case
            std::vector<long long> a_cases_width = std::vector<long long>();
            // X of each case
            std::vector<long long> a_cases_x = std::vector<long long>();
            // Y of each case
            std::vector<long long> a_cases_y = std::vector<long long>();
            // Page of the game
            std::shared_ptr<GUI_Page> a_gui;
            // Size of the inner line
            unsigned char a_inner_line_width = 1;
            // Aster system logo
            GUI_Object* a_logo = 0;
            // Death text for the snake
            GUI_Text* a_lose_text = 0;
            // Each other objects in the grid
            std::vector<Snake_Object*> a_objects = std::vector<Snake_Object*>();
            // Number of objects created
            unsigned int a_objects_created = 0;
            // Size of the outer line
            unsigned char a_outer_line_width = 4;
            // Number of pieces created
            unsigned int a_pieces_created = 0;
            // Playground of the game
            GUI_Object* a_playground = 0;
            // Reset button for the snake
            GUI_Text* a_restart_button = 0;
            // Score of the snake
            GUI_Text* a_score = 0;
            // Each pieces of snakes
            std::vector<Snake_Piece*> a_snake_pieces = std::vector<Snake_Piece*>();

            // Texture of the bottom of the head of the snake
            std::shared_ptr<Image> a_bottom_snake_head_texture = std::shared_ptr<Image>();
            // Texture of the bottom of the head of the snake dead
            std::shared_ptr<Image> a_bottom_snake_dead_head_texture = std::shared_ptr<Image>();
            // Current texture of the head of the scane
            std::shared_ptr<Image> a_current_snake_head_texture = std::shared_ptr<Image>();
            // Texture of the left of the head of the snake
            std::shared_ptr<Image> a_left_snake_head_texture = std::shared_ptr<Image>();
            // Texture of the left of the head of the snake dead
            std::shared_ptr<Image> a_left_snake_dead_head_texture = std::shared_ptr<Image>();
            // Texture of the right of the head of the snake
            std::shared_ptr<Image> a_right_snake_head_texture = std::shared_ptr<Image>();
            // Texture of the right of the head of the snake dead
            std::shared_ptr<Image> a_right_snake_dead_head_texture = std::shared_ptr<Image>();
            // Texture of the top of the head of the snake
            std::shared_ptr<Image> a_top_snake_head_texture = std::shared_ptr<Image>();
            // Texture of the top of the head of the snake dead
            std::shared_ptr<Image> a_top_snake_dead_head_texture = std::shared_ptr<Image>();
        };

        // Use the Snake window
        void use_snake(int window_width, int window_height, std::string exec_path);
    }
}

#endif // SCLS_DEMO_SNAKE
