#pragma once

#include "raylib.h"
#include <vector>
#include <utility>
#include <iostream>
#include <cmath>

#define SCREEN_WIDTH 1440
#define SCREEN_HEIGHT 810

const float CANVAS_WIDTH = SCREEN_WIDTH;
const float CANVAS_HEIGHT = 0.97f * SCREEN_HEIGHT;


enum Button_ID { 
	BRUSH = 1, 
	ERASER = 2,
	BACKGROUND_CHANGE = 3, 
	COLOR_RED = 4, 
	COLOR_BLUE = 5, 
	COLOR_GREEN = 6 
};

#if 1
struct Icon {
	Image brush_icon = LoadImage("../asset/brush.png");
	Image erase_icon = LoadImage("../asset/eraser.png");
	Image red_icon = LoadImage("../asset/red-fill.jpg");
	Image blue_icon = LoadImage("../asset/blue-fill.jpg");
	Image green_icon = LoadImage("../asset/green-fill.jpg");

};
#endif // 0

struct Button {
	
	Texture2D texture;
	Rectangle rec_b;
	bool is_selected;
	Button_ID id;
};
struct Toolbar {
	Icon icon;
	Rectangle rec_t;
	int number_of_buttons;
	std::vector<Button>buttons{};
};

struct Colors {
	Color BackgroundColor = WHITE;
	Color bursh_color = BLACK;
	Color paint_board_color = BackgroundColor;
	Color erase_color = BackgroundColor;
};

struct Boolean {
	bool _brushing = false;
	bool _erasing = false;
	bool _Filling = false;
	bool _Fill_color_background = true;
	bool _clearing = false;
	bool _default = false;
};
Toolbar ToolBar(void);
void DrawToolBar(Toolbar T);
void updateChoice(Toolbar* T, Boolean* is, Colors* color);
void UpdateDrawing(std::vector<std::pair<Vector2, float>>* current_stroke, float radius);
void Default(Boolean* is, Colors* color, float* radius);
void CustomizeRaius(float& radius, KeyboardKey decrease_key, KeyboardKey increase_key);
void UpdateCanvas(Boolean* is, std::vector<std::pair<Vector2, float>>current_stroke, Colors* color);
void Clear_Canvas(Boolean* is, Colors* color);
void Board(float width, float hight);
void Brush_stroke(std::vector<std::pair<Vector2, float>>& current_stroke, Color color);
void Change_Brush_Color(Colors* color);
void Erase_enable_disable(Boolean* is);
void eraser(std::vector<std::pair<Vector2, float>>current_position, Color erase_color);
void Fill_enable_disable(Boolean* is);
void fill(float canvas_width, float canvas_hight, Color color);
void Filling_Color_Change(Boolean* is, Colors* color);
void mouseBrushAnimation(float radius, float board_width, float board_hight, Color c);
void MouseAnimation(Boolean* is, Colors* color, Toolbar* tb, float radius);
void eraserCursorAnimation(float radius, float board_width, float board_hight, Color background_color);
void shortcutMessage(Vector2 position, std::string m, int font_size);
void Message(Boolean * is);
