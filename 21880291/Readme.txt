# Chương trình tra từ điển

Chương trình cho phép người dùng nhập vào 1 từ Tiếng anh tra được ý nghĩa của từ đó.

## Cấu trúc thư mục
/21880291
├── build
├── fileOPTED
│   ├── A.html
│   ├── B.html
│   ├── C.html
│   ├── ...
│   └── Z.html
├── include
│   ├── binary_tree.h
│   └── queue.h
├── src
│   ├── binary_tree.c
│   ├── queue.c
│   └── main.c 
├── Makefile 
├── Readme.md  
├── 21880291.docx    


- include/: Tệp tiêu đề. (Header files .h)
- src/: Tệp mã nguồn. ( .c)
- build/: Thư mục chứa tệp đối tượng đã biên dịch và tệp thực thi.
- fileOPTED/: Dữ liệu cho từ điển.
- Makefile: Tự động hóa quy trình biên dịch.

## Cách biên dịch và kiểm tra

1. Chạy `make` để biên dịch dự án và chạy thử nghiệm.
2. Chạy `make clean` để xóa thư mục biên dịch.

ví dụ thực hiện mã:
```
dcviet@pop-os:~/gitRepo/khtn/cdtcdl/bt2/21880291$ make
gcc -Iinclude -c src/binary_tree.c -o build/binary_tree.o
gcc -o build/dictionary build/binary_tree.o build/queue.o build/main.o
dcviet@pop-os:~/gitRepo/khtn/cdtcdl/bt2/21880291$ ./build/dictionary 
//cần chờ để chương trình nạp dữ liệu từ điển
Nhap tu de tra cuu (hoac '00' de thoat): a

Nghia cua tu 'a': : ) The first letter of the English and of many other alphabets. The capital A of the alphabets of Middle and Western Europe, as also the small letter (a), besides the forms in Italic, black letter, etc., are all descended from the old Latin A, which was borrowed from the Greek Alpha, of the same form; and this was made from the first letter (/) of the Phoenician alphabet, the equivalent of the Hebrew Aleph, and itself from the Egyptian origin. The Aleph was a consonant letter, with a guttural breath sound th:  was not an element of Greek articulation; and the Greeks took it to represent thei; : ) The name of the sixth tone in the model major scale (that in C), or the first tone of the minor scale, which is named after it the scale in A minor. The second string of the violin is tuned to the A in the treble staff. -- A sharp (A/) is the name of a musical tone intermediate between A and B. -- A flat (A/) is the name of a tone intermediate between A and G.; : ) An adjective, commonly called the indefinite article, and signifying one or any, but less emphatically.; : ) In each; to or for each; as, "twenty leagues a day", "a hundred pounds a year", "a dollar a yard", etc.; prep.: ) In; on; at; by.; prep.: ) In process of; in the act of; into; to; -- used with verbal substantives in -ing which begin with a consonant. This is a shortened form of the preposition an (which was used before the vowel sound); as in a hunting, a building, a begging.; : ) Of.; : ) A barbarous corruption of have, of he, and sometimes of it and of they.; : ) An expletive, void of sense, to fill up the meter

Nhap tu de tra cuu (hoac '00' de thoat): 00
```