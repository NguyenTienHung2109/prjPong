I. Hướng dẫn cài đặt:
- Cài các file cpp, header và folder assets chứa các file wav, mp3 vào trong cùng 1 folder lớn.
- Tải và cài đặt thêm các phần sdl sau để chương trình hoạt động:
+ SDL2.dll
+ SDL2_mixer.dll
+ SDL2_ttf.dll
+ SDL2_image.dll

II. Mô tả trò chơi
- Link youtube mô tả trò chơi: https://www.youtube.com/watch?v=npPpVJ8FRhE
- Trò chơi tên là PONG, là trò chơi bóng bàn 2D dùng thanh chắn để không cho bóng lọt qua nền trái hoặc phải của màn hình. Nếu để bóng lọt qua, đối phương sẽ ghi được điểm.
- Game được cài chế độ chơi 1 người và 2 người, thêm vào đó là 1 màn hình menu và chức năng pause game.
- Người dành được 5 điểm trước sẽ là người chiến thắng.
- Khi ở trong Menu hay khi dừng trò chơi, người chơi di chuyển giữa các lựa chọn bằng các nút 'W' hoặc 'PG UP' để di chuyển lên trên và 'S' hoặc 'PG DOWN' để di chuyển xuống dưới.
- Để lựa chọn các nút bấm khi ở Menu hoặc Pause, người chơi sẽ sử dụng nút 'Space bar' trên bàn phím.
- Để dừng trò chơi, người chơi ấn nút 'P' trên bàn phím. 
- Trong chế độ 1 người chơi, người chơi sẽ điều khiển thanh chắn của mình bằng 2 nút 'W' để di chuyển lên và 'S' để di chuyển xuống.
- Trong chế độ 2 người chơi, người chơi 1 sẽ điều khiển thanh chắn của mình bằng 2 nút 'W' để di chuyển lên và 'S' để di chuyển xuống, còn người chơi 2 sẽ điều khiển thanh chắn của mình bằng 2 nút 'PG UP' để di chuyển lên và 'PG DOWN' để di chuyển xuống.
- Khi người chơi số 1 dành được 4 điểm, thanh chắn của người chơi số 2 sẽ chuyển sang màu vàng và gia tăng kích thước để dễ dàng che chắn quả bóng hơn, đồng thời màu quả bóng sẽ được chuyển sang màu đỏ. Điều tương tự cũng sẽ xảy ra khi người chơi số 2 đạt được 4 điểm.
- Các kĩ thuật được sử dụng trong phần code: 
+ con trỏ: các con trỏ được dùng để chỉ đến các phông chữ để hiển thị các các phím trong menu và pause; các đồ hoạ được chỉ đến là các hình chữ nhật SDL_Rect tạo hình quả bóng hay bàn di chuyển của 2 người chơi; ngoài ra còn chỉ đến Mix_Music (nhạc background) và Mix_Chunk (sound effect).
+ đồ hoạ và âm thanh SDL: Như em đã nói ở trên, project có sử dụng SDL_TTF và SDL_Mixer để viết các ký tự trong game và tạo hiệu ứng âm thanh mỗi khi chuyển đổi trạng thái chọn nút bấm (ví dụ như khi bấm di chuyển con trỏ ở phần menu thì sẽ có sound effect), thêm vào đó là 2 background được chạy xuyên suốt, 1 bài nhạc cho phần menu và 1 bài nhạc cho phần game. 
+ string dùng để cập nhật điểm, ghi chữ và xuất ra màn hình.
+ Hàm serve() được dùng để reset các trạng thái của 2 thanh chắn lẫn quả bóng về vị trí khởi đầu (2 thanh chắn và quả bóng sẽ về giữa màn hình, nếu là lượt chẵn thì quả bóng sẽ di chuyển từ trái sang phải, còn khi là lượt lẻ thì ngược lại. 
+ Các hàm input1() và update1() lần lượt được dùng để cập nhật trạng thái của bàn phím và trạng thái game (vị trí bảng của 2 người chơi lẫn quả bóng) trong chế độ 1 người chơi. Trong chế độ 1 người chơi này, AI (người chơi 2) sẽ tự động di chuyển theo hướng lên xuống của quả bóng, khi toạ độ trục y của quả bóng nhỏ hơn toạ độ điểm giữa của người chơi 2, thanh chắn của người chơi 2 sẽ di chuyển lên trên và ngược lại, vậy nên điểm trái bóng hướng đến thường là điểm giữa của thanh chắn, trừ trường hợp thanh chắn không kịp di chuyển đến vị trí của trái bóng.
+ Tương tự, các hàm input2() và update2() được dùng để cập nhật trạng thái bàn phím và trạng thái game trong chế độ 2 người chơi.
+ Hàm write() được dùng để xuất ra các dòng kí tự trên màn hình game. Ta có thể tự do điều chỉnh màu, kích thước, vị trí của dòng chữ ta muốn xuất ra màn hình bằng hàm này. 
+ Hàm InputMenu() và Menu() lần lượt được dùng để cập nhật trạng thái của bàn phím và xuất ra hình ảnh của Menu trên màn hình game.
+ Hàm Pause() và Win() lần lượt được dùng để cập nhật trạng thái của bàn phím lẫn xuất ra màn hình khi dừng game bằng nút 'P' hoặc khi 1 trong 2 người chơi giành được chiến thắng. 
- Kết luận: Theo em, Pong có thể được coi là một trò chơi hoàn chỉnh, tuy còn thô sơ và có thể cải thiện ở một số mặt như cài đặt thêm phông nền hay hiệu ứng animation khi dành chiến thắng. Nếu có thể phát triển thêm, em muốn thêm 1 vài tính năng như nhặt item để điều chỉnh tốc độ di chuyển của quả bóng hay khả năng di chuyển của thanh chắn. 
- Điều tâm đắc nhất với em sau khi hoàn thành dự án lớn lần này là cách quản lý code/file trong 1 project sao cho ngăn nắp, hợp lý và khoa học. Tuy lúc khởi đầu em có những sự bối rối nhất định, em dần học được cách tạo khung cho trò chơi rồi thêm vào những tính năng mới, qua đó cải thiện nhiều về tư duy lẫn khả năng viết code của bản thân. 
