#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float x, y, width, height;
    char fill[20];
} Rectangle;

typedef struct {
    float cx, cy, radius;
    char fill[20];
} Circle;

typedef struct {
    float cx, cy, rx, ry;
    char fill[20];
} Ellipse;

typedef struct {
    float x1, y1, x2, y2;
    char stroke[20];
} Line;

typedef struct {
    int pointCount;
    float *points; 
    char stroke[20];
} Polyline;

typedef struct {
    int pointCount;
    float *points; 
    char fill[20];
} Polygon;

typedef struct {
    float x, y;
    char content[100];
    char fill[20];
} Text;


void writeRectangle(FILE *file, Rectangle rect);
void writeCircle(FILE *file, Circle circle);
void writeEllipse(FILE *file, Ellipse ellipse);
void writeLine(FILE *file, Line line);
void writePolyline(FILE *file, Polyline polyline);
void writePolygon(FILE *file, Polygon polygon);
void writeText(FILE *file, Text text);

void drawChessBoard(FILE *file, int size, float squareSize);
void drawStar(FILE *file, float cx, float cy, float outerRadius, float innerRadius);
void drawSun(FILE *file, float cx, float cy, float radius);
