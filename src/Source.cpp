#pragma once
#include "source.h"

Toolbar ToolBar(void) {
    Toolbar toolbar;
    Button brush;
    //brush.texture = LoadTextureFromImage(toolbar.icon.brush_icon);
    //brush.rec_b = { 5,40,(float)brush.texture.width,(float)brush.texture.height };
    brush.rec_b = { 5,40,50.0f,50.0f };
    brush.is_selected = false;
    brush.id = BRUSH;

    Button erase;
    //erase.texture = LoadTextureFromImage(toolbar.icon.erase_icon);
    //erase.rec_b = { 5 , 40 + brush.rec_b.width + 5 , (float)erase.texture.width,(float) erase.texture.height };
    erase.rec_b = { 5 , 40 + brush.rec_b.width + 5 , 50.0f,50.0f };
    erase.is_selected = false;
    erase.id = ERASER;

    Button background_changer;
    background_changer.rec_b = { 5,erase.rec_b.y + 50.0f + 5.0f,50.0f,50.0f };
    background_changer.is_selected = false;
    background_changer.id = BACKGROUND_CHANGE;

    Button red;
    //red.texture = LoadTextureFromImage(toolbar.icon.red_icon);
    //red.rec_b = { 5 , erase.rec_b.y + red.texture.height + 5 , (float)red.texture.width,(float)red.texture.height };
    red.rec_b = { 5 , background_changer.rec_b.y + 50.0f + 5.0f , 50.0f,50.0f };
    red.is_selected = false;
    red.id = COLOR_RED;

    Button blue;
    //blue.texture = LoadTextureFromImage(toolbar.icon.blue_icon);
    //blue.rec_b = { 5 , red.rec_b.y + blue.texture.height + 5 , (float)blue.texture.width,(float)blue.texture.height };
    blue.rec_b = { 5 , red.rec_b.y + 50.0f + 5 , 50.0f,50.0f };
    blue.is_selected = false;
    blue.id = COLOR_BLUE;

    Button green;
    //green.texture = LoadTextureFromImage(toolbar.icon.green_icon);
    //green.rec_b = { 5 , blue.rec_b.y + green.texture.height + 5, (float)green.texture.width,(float)green.texture.height };
    green.rec_b = { 5 , blue.rec_b.y + 50.0f + 5, 50.0f,50.0f };
    green.is_selected = false;
    green.id = COLOR_GREEN;
#if 0
    UnloadImage(toolbar.icon.red_icon);
    UnloadImage(toolbar.icon.blue_icon);
    UnloadImage(toolbar.icon.green_icon);
    UnloadImage(toolbar.icon.brush_icon);
    UnloadImage(toolbar.icon.erase_icon);
#endif
    toolbar.number_of_buttons = 7;
    toolbar.rec_t = { 5,40,brush.rec_b.width,toolbar.number_of_buttons * (brush.rec_b.height - 4) };

    toolbar.buttons.push_back(brush);
    toolbar.buttons.push_back(erase);
    toolbar.buttons.push_back(background_changer);
    toolbar.buttons.push_back(red);
    toolbar.buttons.push_back(blue);
    toolbar.buttons.push_back(green);
    return toolbar;
}

void DrawToolBar(Toolbar T) {
    DrawRectangleRec(T.rec_t, BLACK);
    for (auto& itr : T.buttons) {
        switch (itr.id)
        {
        case BRUSH:
            DrawRectangleRec(itr.rec_b, WHITE);
            //DrawTexture(itr.texture,itr.rec_b.x,itr.rec_b.y,WHITE);
            DrawRectangleLines((int) itr.rec_b.x, (int) itr.rec_b.y, (int)itr.rec_b.width, (int)itr.rec_b.height, BLACK);
            break;
        case ERASER:
            DrawRectangleRec(itr.rec_b, WHITE);
            //DrawTexture(itr.texture, itr.rec_b.x, itr.rec_b.y, WHITE);
            DrawRectangleLines((int)itr.rec_b.x, (int)itr.rec_b.y, (int)itr.rec_b.width, (int)itr.rec_b.height, BLACK);
            break;
        case BACKGROUND_CHANGE:
            DrawRectangleRec(itr.rec_b, WHITE);
            DrawRectangleLines((int)itr.rec_b.x, (int)itr.rec_b.y, (int)itr.rec_b.width, (int)itr.rec_b.height, BLACK);
            break;
        case COLOR_RED:
            DrawRectangleRec(itr.rec_b, RED);
            //DrawTexture(itr.texture, itr.rec_b.x, itr.rec_b.y, WHITE);
            DrawRectangleLines((int)itr.rec_b.x, (int)itr.rec_b.y, (int)itr.rec_b.width, (int)itr.rec_b.height, BLACK);
            break;
        case COLOR_BLUE:
            DrawRectangleRec(itr.rec_b, BLUE);
            //DrawTexture(itr.texture, itr.rec_b.x, itr.rec_b.y, WHITE);
            DrawRectangleLines((int)itr.rec_b.x, (int)itr.rec_b.y, (int)itr.rec_b.width, (int)itr.rec_b.height, BLACK);
            break;
        case COLOR_GREEN:
            DrawRectangleRec(itr.rec_b, GREEN);
            //DrawTexture(itr.texture, itr.rec_b.x, itr.rec_b.y, WHITE);
            DrawRectangleLines((int)itr.rec_b.x, (int)itr.rec_b.y, (int)itr.rec_b.width, (int)itr.rec_b.height, BLACK);
            break;

        default:
            break;
        }
    }
#if 0
    for (auto& itr : T.buttons) {
        UnloadTexture(itr.texture);
    }
#endif
}

void updateChoice(Toolbar* T, Boolean* is, Colors* color) {
    for (auto& itr : T->buttons) {
        Button* btn = &itr;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionPointRec(GetMousePosition(), btn->rec_b)) {
                switch (btn->id) {
                case BRUSH:
                    is->_brushing = true;
                    if (is->_erasing) {
                        is->_erasing = false;
                    }
                    //std::cout << "BRUSH selected" << std::endl;
                    break;
                case ERASER:
                    if (!is->_erasing) {
                        is->_erasing = true;
                    }
                    else {
                        is->_erasing = false;
                    }
                    std::cout << "ERASE selected" << std::endl;
                    break;
#if 0
                case BACKGROUND_CHANGE:
                    if (!is->_Filling and !is->_Fill_color_background) {
                        is->_Filling = true;
                        is->_Fill_color_background = true;
                        is->_brushing = false;
                    }
                    else {
                        is->_Filling = false;
                        is->_Fill_color_background = false;
                        is->_brushing = true;
                    }
                    std::cout << "FILLING" << std::endl;
                    for (auto& itr : T->buttons) {
                        if (CheckCollisionPointRec(GetMousePosition(), itr.rec_b)) {
                            switch (itr.id) {
                            case COLOR_RED:
                                color->paint_board_color= RED;
                                break;
                            case COLOR_BLUE:
                                color->paint_board_color = BLUE;
                                break;
                            case COLOR_GREEN:
                                color->paint_board_color = GREEN;
                                break;
                            default:
                                break;
                            }
                        }
                    }
                    break;
#endif
                case COLOR_RED:
                    color->bursh_color = RED;
                    std::cout << "BRUSH_COLOR_RED selected" << std::endl;
                    break;
                case COLOR_BLUE:
                    color->bursh_color = BLUE;
                    std::cout << "BRUSH_COLOR_BLUE selected" << std::endl;
                    break;
                case COLOR_GREEN:
                    color->bursh_color = GREEN;
                    std::cout << "BRUSH_COLOR_GREEN selected" << std::endl;
                }
            }
        }
    }


}
void Default(Boolean* is, Colors* color, float* radius) {
    is->_default = true;
    color->bursh_color = BLACK;
    *radius = 5;
}
void CustomizeRaius(float& radius, KeyboardKey decrease_key, KeyboardKey increase_key) {
    if (IsKeyDown(decrease_key)) {
        radius -= 0.1f;
    }
    else if (IsKeyDown(increase_key)) {
        radius += 0.1f;
    }
}

void Brush_stroke(std::vector<std::pair<Vector2, float>>& current_stroke, Color color) {
    for (auto& itr : current_stroke) {
        DrawCircle((int)itr.first.x, (int)itr.first.y, itr.second, color);
    }

    for (int i = 1; i < current_stroke.size(); i++) {
        float x2 = current_stroke.at(i).first.x;
        float x1 = current_stroke.at(i - 1).first.x;
        float y2 = current_stroke.at(i).first.y;
        float y1 = current_stroke.at(i - 1).first.y;
        float avrg_radius;

        float gap =(float) sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

        if (gap == 0) continue;
        if (current_stroke[i].second != current_stroke[i - 1].second) {
            avrg_radius = (current_stroke[i].second + current_stroke[i - 1].second) / 2;
        }
        else {
            avrg_radius = current_stroke[i].second;
        }
        int number_of_circle = gap / avrg_radius;
        //if (number_of_circle == 0) continue; // Skip if no intermediate circles

        for (int j = 1; j <= number_of_circle; j++) {
            float t = static_cast<float>(j) / number_of_circle;
            float vx = x1 * (1 - t) + x2 * t;
            float vy = y1 * (1 - t) + y2 * t;
            DrawCircle((int)vx, (int)vy, avrg_radius, color);
        }
    }
}
void UpdateDrawing(std::vector < std::pair<Vector2, float>>* current_stroke, float radius) {
    Vector2 MousePosition = GetMousePosition();

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        //MousePosition = { MousePosition.x - 150 , (float)(MousePosition.y - ((CANVAS_HEIGHT - CANVAS_HEIGHT * 0.8) / 4.0f)) };
        current_stroke->push_back(std::make_pair(MousePosition, radius));
    }
    else if (IsMouseButtonUp(MOUSE_BUTTON_LEFT)) {
        if (!current_stroke->empty()) {
            current_stroke->clear();
        }
    }
}
void Change_Brush_Color(Colors* color) {
    if (IsKeyDown(KEY_R)) {
        //choice_your_color = RED;
        color->bursh_color = RED;

    }
    else if (IsKeyDown(KEY_B)) {
        //choice_your_color = BLUE;
        color->bursh_color = BLUE;
    }
    else if (IsKeyDown(KEY_G)) {
        //choice_your_color = GREEN;
        color->bursh_color = GREEN;
    }
}
void UpdateCanvas(Boolean* is, std::vector<std::pair<Vector2, float>>current_stroke, Colors* color) {
    if (is->_erasing) {
        eraser(current_stroke, color->erase_color);
    }
    else {

        Brush_stroke(current_stroke, color->bursh_color);
    }

    if (is->_clearing) {

        fill(CANVAS_WIDTH, CANVAS_HEIGHT, color->BackgroundColor);
    }

    if (is->_Filling and !is->_Fill_color_background) {
        fill(CANVAS_WIDTH, CANVAS_HEIGHT, color->paint_board_color);
    }
}

void Board(float width, float hight) {

    DrawRectangleLines(0, 0, (int) width, (int) hight, BLACK);
}
void mouseBrushAnimation(float radius, float board_width, float board_hight, Color c) {
    Vector2 mouse_position = GetMousePosition();
#if 1
    if ((mouse_position.x >= 0 and mouse_position.x <= board_width)
        and (mouse_position.y >= 0 and mouse_position.y <= board_hight)) {
#endif

        DrawCircle((int)mouse_position.x, (int)mouse_position.y, radius + 1, BLACK);
        DrawCircle((int)mouse_position.x, (int)mouse_position.y, radius, c);
    }
}

void eraser(std::vector<std::pair<Vector2, float>> current_position, Color erase_color) {
    Brush_stroke(current_position, erase_color);
}

void eraserCursorAnimation(float radius, float board_width, float board_hight, Color erase_color) {
    mouseBrushAnimation(radius, board_width, board_hight, WHITE);
}
void Erase_enable_disable(Boolean* is) {
    if (!is->_erasing) {

        is->_erasing = true;
    }
    else {

        is->_erasing = false;
    }
}
void Fill_enable_disable(Boolean* is) {

    if (!is->_Filling) {
        is->_Filling = true;
        is->_default = false;

    }
    else {
        is->_Filling = false;
        is->_default = true;
    }
}
void fill(float canvas_width, float canvas_hight, Color color) {
    DrawRectangle(0, 0, (int)canvas_width, (int)canvas_hight, color);
}

void Filling_Color_Change(Boolean* is, Colors* color) {

    if (IsKeyPressed(KEY_R)) {
        color->paint_board_color = RED;
        is->_Fill_color_background = false;
        std::cout << "RED FILLING" << std::endl;
    }
    else if (IsKeyPressed(KEY_G)) {
        color->paint_board_color = GREEN;
        is->_Fill_color_background = false;
    }
    else if (IsKeyPressed(KEY_B)) {
        color->paint_board_color = BLUE;
        is->_Fill_color_background = false;
    }
    else if (IsKeyPressed(KEY_D)) {
        color->paint_board_color = BLACK;
        is->_Fill_color_background = true;
        is->_default = true;
    }
    color->erase_color = color->paint_board_color;
}
void Clear_Canvas(Boolean* is, Colors* color) {
    if (!is->_clearing) {
        is->_clearing = true;
        is->_default = true;
        color->erase_color = color->BackgroundColor;
    }
    else {
        is->_clearing = false;
        is->_default = false;
    }
}

void MouseAnimation(Boolean* is, Colors* color, Toolbar* tb, float radius) {
    if (CheckCollisionPointRec(GetMousePosition(), tb->rec_t)) {
        return;
    }
    if (is->_erasing) {
        eraserCursorAnimation(radius, CANVAS_WIDTH, CANVAS_HEIGHT, color->erase_color);//canvas width,hight
    }
    else {
        mouseBrushAnimation(radius, CANVAS_WIDTH, CANVAS_HEIGHT, color->bursh_color);//canvas width ,hight
    }
}
void shortcutMessage(Vector2 position, std::string m, int font_size) {
    DrawText(m.c_str(), (int)position.x, (int) position.y, font_size, BLACK);
}

void Message(Boolean* is) {
    int font_size = 10;
    Vector2 message_position = { 25,0.98f * SCREEN_HEIGHT };
    if (is->_clearing) {
        shortcutMessage(message_position, "CLEARING", font_size);
    }
    else if (is->_erasing) {
        shortcutMessage(message_position, "ERASING", font_size);
    }
    else if (is->_Filling) {
        shortcutMessage(message_position, "CHANGING BACKGROUND", font_size);
    }
    else {
        shortcutMessage(message_position, "DRAWING", font_size);
    }
}
