#include <stdio.h>
#include <math.h>
#include "svg_shape.h"

int main()
{
    FILE *file;
    char filename[100];
    int choice;

    while (1)
    {
        printf("Nhập tên tệp SVG để lưu: ");
        scanf("%s", filename);
        file = fopen(filename, "w");

        if (!file)
        {
            printf("Không thể mở tệp để ghi!\n");
            return 1;
        }

        fprintf(file, "<svg xmlns=\"http://www.w3.org/2000/svg\">\n");

        while (1)
        {
            printf("Nhập loại đối tượng (1: Rectangle, 2: Circle, 3: Ellipse, 4: Line, 5: Polyline, 6: Polygon, 7: Text, 8: Bản đồ vua, 9: Ngôi sao, 10: Mặt trời, 0: Thoát): ");
            scanf("%d", &choice);

            if (choice == 0)
                break;

        switch (choice)
        {
        case 1:
        { // Rectangle
            Rectangle rect;
            printf("Nhập tọa độ x: ");
            scanf("%f", &rect.x);
            printf("Nhập tọa độ y: ");
            scanf("%f", &rect.y);
            printf("Nhập chiều rộng: ");
            scanf("%f", &rect.width);
            printf("Nhập chiều cao: ");
            scanf("%f", &rect.height);
            printf("Nhập màu (hoặc nhấn Enter để không có màu): ");
            scanf("%s", rect.fill);
            writeRectangle(file, rect);
            break;
        }
        case 2:
        { // Circle
            Circle circle;
            printf("Nhập tọa độ cx: ");
            scanf("%f", &circle.cx);
            printf("Nhập tọa độ cy: ");
            scanf("%f", &circle.cy);
            printf("Nhập bán kính: ");
            scanf("%f", &circle.radius);
            printf("Nhập màu (hoặc nhấn Enter để không có màu): ");
            scanf("%s", circle.fill);
            writeCircle(file, circle);
            break;
        }
        case 3:
        { // Ellipse
            Ellipse ellipse;
            printf("Nhập tọa độ cx: ");
            scanf("%f", &ellipse.cx);
            printf("Nhập tọa độ cy: ");
            scanf("%f", &ellipse.cy);
            printf("Nhập bán kính x (rx): ");
            scanf("%f", &ellipse.rx);
            printf("Nhập bán kính y (ry): ");
            scanf("%f", &ellipse.ry);
            printf("Nhập màu (hoặc nhấn Enter để không có màu): ");
            scanf("%s", ellipse.fill);
            writeEllipse(file, ellipse);
            break;
        }
        case 4:
        { // Line
            Line line;
            printf("Nhập tọa độ x1: ");
            scanf("%f", &line.x1);
            printf("Nhập tọa độ y1: ");
            scanf("%f", &line.y1);
            printf("Nhập tọa độ x2: ");
            scanf("%f", &line.x2);
            printf("Nhập tọa độ y2: ");
            scanf("%f", &line.y2);
            printf("Nhập màu stroke (hoặc nhấn Enter để không có màu): ");
            scanf("%s", line.stroke);
            writeLine(file, line);
            break;
        }
        case 5:
        { // Polyline
            Polyline polyline;
            printf("Nhập số điểm: ");
            scanf("%d", &polyline.pointCount);
            polyline.points = (float *)malloc(polyline.pointCount * 2 * sizeof(float));
            for (int i = 0; i < polyline.pointCount; i++)
            {
                printf("Nhập tọa độ điểm %d (x, y): ", i + 1);
                scanf("%f %f", &polyline.points[i * 2], &polyline.points[i * 2 + 1]);
            }
            printf("Nhập màu stroke: ");
            scanf("%s", polyline.stroke);
            writePolyline(file, polyline);
            free(polyline.points);
            break;
        }
        case 6:
        { // Polygon
            Polygon polygon;
            printf("Nhập số điểm: ");
            scanf("%d", &polygon.pointCount);
            polygon.points = (float *)malloc(polygon.pointCount * 2 * sizeof(float));
            for (int i = 0; i < polygon.pointCount; i++)
            {
                printf("Nhập tọa độ điểm %d (x, y): ", i + 1);
                scanf("%f %f", &polygon.points[i * 2], &polygon.points[i * 2 + 1]);
            }
            printf("Nhập màu (hoặc nhấn Enter để không có màu): ");
            scanf("%s", polygon.fill);
            writePolygon(file, polygon);
            free(polygon.points);
            break;
        }
        case 7:
        { // Text
            Text text;
            printf("Nhập tọa độ x: ");
            scanf("%f", &text.x);
            printf("Nhập tọa độ y: ");
            scanf("%f", &text.y);
            printf("Nhập nội dung văn bản: ");
            scanf(" %[^\n]", text.content); // Đọc cả dòng
            printf("Nhập màu (hoặc nhấn Enter để không có màu): ");
            scanf("%s", text.fill);
            writeText(file, text);
            break;
        }
        case 8:
        {// Bàn cờ vua
            int size = 8; 
            float squareSize;
            printf("Nhập kích thước mỗi ô vuông (ví dụ 50): ");
            scanf("%f", &squareSize);
            drawChessBoard(file, size, squareSize);
            break;
        }
        case 9:
        { // Ngôi sao
            float cx, cy, outerRadius, innerRadius;
            printf("Nhập tọa độ cx: ");
            scanf("%f", &cx);
            printf("Nhập tọa độ cy: ");
            scanf("%f", &cy);
            printf("Nhập bán kính ngoài: ");
            scanf("%f", &outerRadius);
            printf("Nhập bán kính trong: ");
            scanf("%f", &innerRadius);
            
            drawStar(file, cx, cy, outerRadius, innerRadius);
            break;
        }

        case 10:
        { // Mặt trời
            float cx, cy, radius;
            printf("Nhập tọa độ cx: ");
            scanf("%f", &cx);
            printf("Nhập tọa độ cy: ");
            scanf("%f", &cy);
            printf("Nhập bán kính: ");
            scanf("%f", &radius);
            drawSun(file, cx, cy, radius);
            break;
        }
        default:
            printf("Lựa chọn không hợp lệ.\n");
        }
    }

        fprintf(file, "</svg>\n");
        fclose(file);

        printf("Tệp SVG đã được lưu.\n");

        char continueChoice;
        printf("Bạn có muốn tạo tệp SVG mới không? (y/n): ");
        scanf(" %c", &continueChoice);
        if (continueChoice != 'y' && continueChoice != 'Y')
            break;
    }

    return 0;
}
