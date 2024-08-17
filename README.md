
# FLAPPY BIRD BY TU
Demo game và cấu trúc code:
## Giới thiệu game
Flappy bird by Tu là một trò chơi thú vị, nơi bạn sẽ điều khiển nhân vật Bird để vượt qua các chướng ngại vật, ăn vật phẩm, đạt điểm số và mức rank cao nhất có thể. Trò chơi này yêu cầu sự nhanh nhẹn và khéo léo để né tránh các ống cản đường, thu thập khiên bảo vệ và hoa quả tăng điểm. Hãy thử thách khả năng của bạn và xem bạn có thể ghi được bao nhiêu điểm!

# 0. Cách tải game
## Cách 1:
## Cách 2:

# 1. Bắt đầu game:
![Screenshot 2024-08-13 153945](https://github.com/user-attachments/assets/f337329d-78a2-43ac-bbc3-23d46d641f12)

Nhấn tap chuột trái ![chuoitrai](https://github.com/user-attachments/assets/78c289d5-a7a1-4fc5-82e3-f8dc792010e9) hoặc nút lên ↑ hoặc nút Space ─── để bắt đầu chơi game
# 2. Các thành phần trong game
* Bird ![bird2](https://github.com/user-attachments/assets/31fb1bcf-925c-49b0-9f06-de06c507a5c3): Nhân vật chính mà bạn điều khiển  
* Chướng ngại vật cột ![pipe2](https://github.com/user-attachments/assets/179941dc-42b1-4d96-a15e-2ecae4a15cad): Bạn cần đi qua khe giữa 2 cột  
* Chướng ngại vật chim ![penguin](https://github.com/user-attachments/assets/4207a32d-2b3c-4959-bb6c-d0e4123add62): Chướng ngại vật này sẽ đi từ bên phải màn hình qua, bạn cần né nó  
* Fruit ![Strawberry](https://github.com/user-attachments/assets/61c793a0-7e7d-49c1-8b12-d2eb2e1dc0c0): Khi ăn fruit sẽ tăng một số điểm bất kì  
* Khiên bảo vệ ![shield](https://github.com/user-attachments/assets/4e60dc2d-37dd-4fb1-b576-b892c8da3992): Khiên bảo vệ giúp chim bất tử trong 2s  
* Nút Replay: ![replay](https://github.com/user-attachments/assets/3d2e511d-e5fe-4f57-b577-3757dbd63c23)  
* Nút Pause: ![pause](https://github.com/user-attachments/assets/3d2565bb-5d92-4fbf-9b90-a9abbe76d9d9)  
* Nút Resume: ![resume](https://github.com/user-attachments/assets/35dbb3ca-cc5a-4c50-b463-49f6b11f6484)  
* Tắt/Bật tiếng: ![sound](https://github.com/user-attachments/assets/9c7695ed-3a2f-4e09-8f1c-61ad5850becd)  
* Đất:  
![land](https://github.com/user-attachments/assets/9b4d9eb3-066f-4c46-b507-c5271a097726)
* Pause Tab:  
![pauseTab](https://github.com/user-attachments/assets/55068d52-d691-4dae-b769-4328a136aea4)
* Background:  
![background](https://github.com/user-attachments/assets/dfe18e31-2b94-426e-a5d9-d9ddf82b7c58)
* Game Over:  
![gameOver](https://github.com/user-attachments/assets/f3ff8993-bf85-4ccc-8d02-4dd71573132a)
* Get Ready:  
![message](https://github.com/user-attachments/assets/fa6cf38a-e997-42cc-a418-6baa21b3fac5)
* Các mức rank:

|       Rank       |              |
| :------------:|:-------------:|
|    Unranked          |  ![unranked](https://github.com/user-attachments/assets/5e38b102-0a60-4c13-a55f-5166bd8f778c)|
|     Bronze         |        ![bronze](https://github.com/user-attachments/assets/08a55635-9a35-4b0e-b54f-95ef34947813)      |
|     Silver         |    ![silver](https://github.com/user-attachments/assets/671b94c6-638f-449c-b6bc-0364dcf0ca1c)|
|     Gold        |   ![gold](https://github.com/user-attachments/assets/6107d9b8-ac17-4dc8-af8b-2a865f0933ba)|

# 3. Cách chơi:
Bạn sẽ điều khiển nhân vật Bird để vượt qua các chướng ngại vật, ăn các vật phẩm, đạt điểm số và mức rank cao nhất có thể. Thất bại khi Bird bị va chạm với chướng ngại vật.
## Di chuyển:  
Điều khiển Bird bằng cách nhấn tap chuột trái ![chuoitrai](https://github.com/user-attachments/assets/78c289d5-a7a1-4fc5-82e3-f8dc792010e9) hoặc nút lên ↑ hoặc nút Space ─── để vượt qua các chướng ngại vật.  
Dùng nút ESC để pause game
## Các vật phẩm buff trong game:
Game gồm có 2 vật phẩm Fruit và Khiên sẽ xuất hiện tùy lúc trong game:
* Fruit ![Strawberry](https://github.com/user-attachments/assets/61c793a0-7e7d-49c1-8b12-d2eb2e1dc0c0): Khi ăn fruit sẽ tăng một số điểm bất kì
* Khiên bảo vệ ![shield](https://github.com/user-attachments/assets/4e60dc2d-37dd-4fb1-b576-b892c8da3992): Khiên bảo vệ giúp chim bất tử trong 2s
## Các mức độ khó trong game:
|       Mức điểm       |      Mô tả độ khó        |
| :------------:|:-------------:|
|    0-10         |  Dễ, chỉ cần vượt qua chướng ngại vật các cột|
|     11-40         |        Trung bình, chướng ngại vật các cột di chuyển nhanh hơn, ở mức điểm 21 sẽ có thêm chướng ngại vật chim    |
|     Trên 41         |    Khó, các chướng ngại vật cột di chuyển nhanh hơn và vẫn có chướng ngại vật chim|
## Hệ thống mức rank:
|Điểm |       Rank       |              |
|:------------:| :------------:|:-------------:|
|0-5|    Unranked          |  ![unranked](https://github.com/user-attachments/assets/5e38b102-0a60-4c13-a55f-5166bd8f778c)|
|6-30|     Bronze         |        ![bronze](https://github.com/user-attachments/assets/08a55635-9a35-4b0e-b54f-95ef34947813)      |
|31-70|     Silver         |    ![silver](https://github.com/user-attachments/assets/671b94c6-638f-449c-b6bc-0364dcf0ca1c)|
|>70|     Gold        |   ![gold](https://github.com/user-attachments/assets/6107d9b8-ac17-4dc8-af8b-2a865f0933ba)|

## Một số hình ảnh khi chơi game:
![Screenshot 2024-08-13 170106](https://github.com/user-attachments/assets/50bb1653-2abd-49e0-bee7-172696d0aa3a)
![Screenshot 2024-08-13 170228](https://github.com/user-attachments/assets/321b6dd9-b2fb-4ed1-9364-acb9d4757b5c)
![Screenshot 2024-08-13 170319](https://github.com/user-attachments/assets/bdb493d4-2a2c-4496-8130-313863d6e7cd)
![Screenshot 2024-08-13 170520](https://github.com/user-attachments/assets/3b288c90-72c9-4187-ae0d-d5adcfbc909a)

# 4. Các kĩ thuật sử dụng:
* Sử dụng thư viện SDL2.0
* Sử dụng nhiều class, vector, tách file, các thao tác với file, ...\
* Sử dụng OOP (Lập trình hướng đối tượng) để quản lý đối tượng trong game.
* Các hàm check va chạm
* Tạo ra trọng lực rơi cho con chim
* Xử lý thời gian, thao tác chuột và bàn phím, âm thanh, hình ảnh.
* Sử dụng các kĩ thuật edit, cắt ghép và sưu tầm ảnh để hoàn thiện game

# 5. Nguồn tham khảo:
* Tham khảo cách tách file và cách load hình ảnh và map trên Phát Triển Phần Mềm 123A-Z https://www.youtube.com/@PhatTrienPhanMem123AZ
* Tham khảo về sử dụng SDL trên trang lazyfoo https://lazyfoo.net/tutorials/SDL/
* Hình ảnh, âm thanh được sưu tầm và chủ yếu lấy từ web https://itch.io/game-assets/free

# 6. Hướng phát triển:
* Tối ưu hóa game hơn
* Tạo thêm nhiều vật phẩm
* Hệ thống đua rank giữa những người chơi
* Hệ thống phần thưởng, các vật phẩm hiếm khi ăn được có thể trao đổi giữa các người chơi
















