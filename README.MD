# Dữ liệu và file weight trong quá trình thực hiện project 
- Dữ liệu sử dụng cho việc xây dựng kiến trúc model CNN ([link](https://www.kaggle.com/c/acc-german-traffic-sign-classification/data))
- Dữ liệu cho Yolo ([link](https://drive.google.com/drive/folders/1Js5kipsTQwKDgkAca6mHPOC7H7-Y0Q3Q?usp=sharing))
- File weight và file config cho Yolo ([link](https://drive.google.com/drive/folders/1V4301Dvc6dYwLQJpWwm4SnY9F0Zuop0p?usp=sharing))

# Các thức thực hiện project:
- Đầu tiên thì nhóm chúng em dữ dụng mô hình YOLO để có thể detect được biển báo nằm ở ví trí nào trong bức ảnh đầu vào. Ở phần 2 sẽ có 2 phần chính:
	+ Tiền xử lý dữ liệu: Chia tập dữ liệu đầu vào thành 5 nhóm, với mỗi nhóm là các biển báo có đặc điểm chung có thể quan sát được bằng mắt nhìn.
        + Thực hiện việc training trong tầm 10 đến 12 tiếng để thu được file weight cho project.

- Sau khi có được file weight và detect được biển báo ở vùng nào trong bức ảnh thì bọn em sẽ crop vùng ảnh đó để cho qua model CNN để gán 	nhãn thật cho biển báo.

- Tiếp theo nhóm chúng em tự xây dựng kiến trúc model mạng CNN cho bài toán của mình. Đầu tiên thì nhóm chúng em tham khảo kiến trúc 
model Lenet cho nhận diện chữ số ([link](http://yann.lecun.com/exdb/publis/pdf/lecun-98.pdf)) trong bài báo này thì thu được accuracy cho
tập train khoảng 96%, tuy nhiên thì accuracy cho tập test tập 91%. Sau đó nhóm chúng em thay đổi kiến trúc model và dũng kỹ thuật Dropout
sau bước Pooling thì nhận thấy model có 3 lớp Conv có hiệu năng khá là tốt cho cả tập train lẫn tập test(khoảng 95 % cho tập test).
	
# Run project:
- Run với đầu vào là một bức ảnh: python3 main.py --image path_to_image
- Run với đầu vào là một video : python3 main.py --image path_to_video 
 
