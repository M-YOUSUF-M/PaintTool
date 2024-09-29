#include "source.h"

int main()
{
	Colors color;
	Boolean is;
	Toolbar tb = ToolBar();
	float RADIUS = 5;
	std::vector<std::pair<Vector2, float>> current_stroke{};

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Painting");
	SetTargetFPS(60);

	RenderTexture2D canvas = LoadRenderTexture((int)CANVAS_WIDTH, (int)CANVAS_HEIGHT);//CANVAS_WIDTH , hight
	Rectangle texture_rec = { 0,0,static_cast<float>(canvas.texture.width),static_cast<float>(-canvas.texture.height) };
	Vector2 texture_position = { 0,0 };

	while (!WindowShouldClose()) {
		UpdateDrawing(&current_stroke, RADIUS);
		CustomizeRaius(RADIUS, KEY_Q, KEY_W);
		updateChoice(&tb, &is, &color);

		//color choice
		if (!is._erasing and !is._Filling) {
			Change_Brush_Color(&color);
		}

		//deleting everything
		if (IsKeyPressed(KEY_DELETE)) {
			Clear_Canvas(&is, &color);
		}
		else if (IsKeyDown(KEY_D)) {
			Default(&is, &color, &RADIUS);
		}
		else {
			is._clearing = false;
		}

		//filling enable/disable canvas
		if (IsKeyPressed(KEY_F)) {
			Fill_enable_disable(&is);
			//choice filling color
		}
		if (is._Filling) {
			Filling_Color_Change(&is, &color);
		}

		//Rendering in Texture Mode
		BeginTextureMode(canvas);
		UpdateCanvas(&is, current_stroke, &color);
		Board(CANVAS_WIDTH, CANVAS_HEIGHT);//canvas width,hight
		EndTextureMode();

		//Begin Drawing
		BeginDrawing();
		ClearBackground(color.BackgroundColor);
		DrawTextureRec(canvas.texture, texture_rec, texture_position, color.BackgroundColor);
		DrawToolBar(tb);
		MouseAnimation(&is, &color,&tb, RADIUS);
		Message(&is);
		EndDrawing();
	}
	UnloadRenderTexture(canvas);
	WindowShouldClose();
}