#include <stdio.h>
#include <math.h>
#include "svg_shape.h"

void writeRectangle(FILE *file, Rectangle rect)
{
    fprintf(file, "<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"%s\" />\n",
            rect.x, rect.y, rect.width, rect.height, rect.fill);
}

void writeCircle(FILE *file, Circle circle)
{
    fprintf(file, "<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" />\n",
            circle.cx, circle.cy, circle.radius, circle.fill);
}

void writeEllipse(FILE *file, Ellipse ellipse)
{
    fprintf(file, "<ellipse cx=\"%f\" cy=\"%f\" rx=\"%f\" ry=\"%f\" fill=\"%s\" />\n",
            ellipse.cx, ellipse.cy, ellipse.rx, ellipse.ry, ellipse.fill);
}

void writeLine(FILE *file, Line line)
{
    fprintf(file, "<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke=\"%s\" />\n",
            line.x1, line.y1, line.x2, line.y2, line.stroke);
}

void writePolyline(FILE *file, Polyline polyline)
{
    fprintf(file, "<polyline points=\"");
    for (int i = 0; i < polyline.pointCount; i++)
    {
        fprintf(file, "%f,%f ", polyline.points[i * 2], polyline.points[i * 2 + 1]);
    }
    fprintf(file, "\" stroke=\"%s\" fill=\"none\" />\n", polyline.stroke);
}

void writePolygon(FILE *file, Polygon polygon)
{
    fprintf(file, "<polygon points=\"");
    for (int i = 0; i < polygon.pointCount; i++)
    {
        fprintf(file, "%f,%f ", polygon.points[i * 2], polygon.points[i * 2 + 1]);
    }
    fprintf(file, "\" fill=\"%s\" />\n", polygon.fill);
}

void writeText(FILE *file, Text text)
{
    fprintf(file, "<text x=\"%f\" y=\"%f\" fill=\"%s\">%s</text>\n",
            text.x, text.y, text.fill, text.content);
}

void drawChessBoard(FILE *file, int size, float squareSize)
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            Rectangle rect;
            rect.x = col * squareSize;
            rect.y = row * squareSize;
            rect.width = squareSize;
            rect.height = squareSize;
            // Xác định màu sắc ô vuông strcpy(rect.fill, (row + col) % 2 == 0 ? "white" : "black");
            if ((row + col) % 2 == 0)
            {
                strcpy(rect.fill, "white");
            }
            else
            {
                strcpy(rect.fill, "black");
            }
            writeRectangle(file, rect);
        }
    }
}

// Hàm tạo ngôi sao
void drawStar(FILE *file, float cx, float cy, float outerRadius, float innerRadius) {
    fprintf(file, "<polygon points=\"");
    for (int i = 0; i < 10; i++) {
        float angle = i * (3.14159 / 5) - (3.14159 / 10);
        float radius = (i % 2 == 0) ? outerRadius : innerRadius;
        fprintf(file, "%f,%f ", cx + radius * cos(angle), cy + radius * sin(angle));
    }
    fprintf(file, "\" fill=\"gold\" />\n");
}


// Hàm tạo mặt trời
void drawSun(FILE *file, float cx, float cy, float radius)
{
    fprintf(file, "<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"yellow\" />\n", cx, cy, radius);
    for (int i = 0; i < 12; i++)
    {
        float angle = i * (2 * 3.14159 / 12);
        float x1 = cx + radius * 1.5 * cos(angle);
        float y1 = cy + radius * 1.5 * sin(angle);
        float x2 = cx + radius * 2.0 * cos(angle);
        float y2 = cy + radius * 2.0 * sin(angle);
        writeLine(file, (Line){x1, y1, x2, y2, "orange"});
    }
}
