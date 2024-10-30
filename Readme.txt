# Chương trình tra từ điển

Chương trình cho phép người dùng nhập vào các thông số để tạo file svg.

## Cấu trúc thư mục
/21880291
├── build
├── include
│   ├── svg_shape.h
├── src
│   ├── main.c
│   └── makeSvg.c 
├── Makefile 
├── Readme.md  
├── 21880291.docx    


- include/: Tệp tiêu đề. (Header files .h)
- src/: Tệp mã nguồn. ( .c)
- build/: Thư mục chứa tệp đối tượng đã biên dịch và tệp thực thi.
- Makefile: Tự động hóa quy trình biên dịch.

## Cách biên dịch và kiểm tra

1. Chạy `make` để biên dịch dự án.
2. Chạy `make clean` để xóa thư mục biên dịch.
3. Chạy `./build/svg_program` để chạy chương trình.

ví dụ thực hiện mã:
```
$ ./build/svg_program 
Nhập tên tệp SVG để lưu: s3
Nhập loại đối tượng (1: Rectangle, 2: Circle, 3: Ellipse, 4: Line, 5: Polyline, 6: Polygon, 7: Text, 8: Bản đồ vua, 9: Ngôi sao, 10: Mặt trời, 0: Thoát): 9
Nhập tọa độ cx: 100
Nhập tọa độ cy: 100
Nhập bán kính ngoài: 65
Nhập bán kính trong: 56
Nhập loại đối tượng (1: Rectangle, 2: Circle, 3: Ellipse, 4: Line, 5: Polyline, 6: Polygon, 7: Text, 8: Bản đồ vua, 9: Ngôi sao, 10: Mặt trời, 0: Thoát): 0
Tệp SVG đã được lưu.
Bạn có muốn tạo tệp SVG mới không? (y/n): n
```