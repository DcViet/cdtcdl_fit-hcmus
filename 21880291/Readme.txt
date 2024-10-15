# Mô-đun BigInt 

Mô-đun này triển khai kiểu dữ liệu `BigInt` trong C, hỗ trợ các phép toán cơ bản như cộng, trừ, nhân, chia và tính toán cơ bản cho các số nguyên lớn lên đến 100 chữ số.

## Cấu trúc thư mục
21880291/
├── BigInt/
│	├── include/
│	│   └── BigInt.h
│	├── src/
│	│   └── BigInt.c
│	├── build/
│	├── Makefile	
├── Readme.md
├── 21880291_baocao-bt1.docx    

- include/: Tệp tiêu đề. (Header files .h)
- src/: Tệp mã nguồn. ( .c)
- build/: Thư mục chứa tệp đối tượng đã biên dịch và tệp thực thi.
- Makefile: Tự động hóa quy trình biên dịch.

## Cách biên dịch và kiểm tra

1. Chạy `make` để biên dịch dự án và chạy thử nghiệm.
2. Chạy `make clean` để xóa thư mục biên dịch.

## Ví dụ sử dụng

include `BigInt.h` và liên kết với các tệp đối tượng đã biên dịch.

```
#include "BigInt.h"

// Triển khai mã ở đây
..