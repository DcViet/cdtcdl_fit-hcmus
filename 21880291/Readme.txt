# Mô-đun BigInt 

Mô-đun này triển khai kiểu dữ liệu `BigInt` trong C, hỗ trợ các phép toán cơ bản như cộng, trừ, nhân, chia và tính toán cơ bản cho các số nguyên lớn lên đến 100 chữ số.

## Cấu trúc thư mục
21880291/
├── BigInt/
│	├── include/
│	│   └── BigInt.h
│	├── src/
│	│   ├── BigInt.c
│	│   ├── main.c
│	├── build/
│	├── Makefile	
├── Readme.md
├── 21880291_bt1.docx    

- include/: Tệp tiêu đề. (Header files .h)
- src/: Tệp mã nguồn. ( .c)
- build/: Thư mục chứa tệp đối tượng đã biên dịch và tệp thực thi.
- Makefile: Tự động hóa quy trình biên dịch.

## Cách biên dịch và kiểm tra

1. Chạy `make` để biên dịch dự án và chạy thử nghiệm.
2. Chạy `make clean` để xóa thư mục biên dịch.

ví dụ thực hiện mã:
```
CPSs-MacBook-Pro:BigInt cps$ make
gcc -Wall -g -Iinclude -c src/main.c -o build/main.o
gcc -Wall -g -Iinclude -c src/BigInt.c -o build/BigInt.o
gcc -Wall -g -Iinclude -o build/BigIntTest build/main.o build/BigInt.o
CPSs-MacBook-Pro:BigInt cps$ ./build/BigIntTest
a (base 10): 123456789012345678901234567890
b (base 10): 987654321098765432109876543210
numHex (base 16): 1A2B3C4D5E6F
c (from int): 123456789
c (to int): 123456789
a + b = 1111111110111111111011111111100
b - a = 864197532086419753208641975320
a * b = 16666666516666666651666666665150
b / a = 8
b % a = 987654321098765432109876542130
negate(a) = -123456789012345678901234567890
abs(a) = 123456789012345678901234567890
a ^ 2 = 162
sqrt(a1) = 4
cbrt(b1) = 3
-1(a<b)
```