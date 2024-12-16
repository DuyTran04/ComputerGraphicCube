#include <GL/glut.h>
#include <iostream>

//Các biến vị trí của camera
GLdouble eyeX = 0.0;
GLdouble eyeY = 0.0;
GLdouble eyeZ = 5.0;
//Các biến hướng nhìn của camera 
GLdouble centerX = 0.0;
GLdouble centerY = 0.0;
GLdouble centerZ = 0.0;
//Các biến hướng đứng của camera 
GLdouble upX = 0.0;
GLdouble upY = 0.1;
GLdouble upZ = 0.0;

// Giá trị tối thiểu và tối đa của Eye
GLdouble minEye = -10.0;
GLdouble maxEye = 10.0;
// Giá trị tối thiểu và tối đa của Center
GLdouble minCenter = -10.0;
GLdouble maxCenter = 10.0;
// Giá trị tối thiểu và tối đa của Up
GLdouble minUp = -10.0;
GLdouble maxUp = 10.0;

// Biến để lưu giá trị thay đổi khi bấm phím, tốc độ camera 
const double speed = 0.2;
// Hàm vẽ trục tọa độ
void drawCoordinates()
{
    glBegin(GL_LINES);
    // X-axis (red)
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-100, 0.0, 0.0);
    glVertex3f(100, 0.0, 0.0);
    // Y-axis (green)
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0, -100.0, 0.0);
    glVertex3f(0, 100.0, 0.0);
    // Z-axis (blue)
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0, 0, -100.0);
    glVertex3f(0, 0, 100.0);
    glEnd();

}

// Hàm vẽ hình lập phương
void drawCube(GLdouble size)
{
    GLdouble Size = size / 1.0;

    glBegin(GL_QUADS);

    // Mặt trước (màu đỏ)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-Size, -Size, Size);
    glVertex3f(Size, -Size, Size);
    glVertex3f(Size, Size, Size);
    glVertex3f(-Size, Size, Size);

    // Mặt sau (màu xanh lá cây)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-Size, -Size, -Size);
    glVertex3f(-Size, Size, -Size);
    glVertex3f(Size, Size, -Size);
    glVertex3f(Size, -Size, -Size);

    // Mặt trên (màu xanh dương)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-Size, Size, -Size);
    glVertex3f(-Size, Size, Size);
    glVertex3f(Size, Size, Size);
    glVertex3f(Size, Size, -Size);

    // Mặt dưới (màu vàng)
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-Size, -Size, -Size);
    glVertex3f(Size, -Size, -Size);
    glVertex3f(Size, -Size, Size);
    glVertex3f(-Size, -Size, Size);

    // Mặt bên trái (màu cam)
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-Size, -Size, -Size);
    glVertex3f(-Size, -Size, Size);
    glVertex3f(-Size, Size, Size);
    glVertex3f(-Size, Size, -Size);

    // Mặt bên phải (màu tím)
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(Size, -Size, Size);
    glVertex3f(Size, -Size, -Size);
    glVertex3f(Size, Size, -Size);
    glVertex3f(Size, Size, Size);

    glEnd();
}

// Hàm hiển thị
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // Thiết lập vị trí camera
    gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);
    // Vẽ hình lập phương và trục tọa độ
    drawCube(1.0);
    drawCoordinates();
    glutSwapBuffers();
}

// Hàm thay đổi kích thước cửa sổ
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}

// Hàm đặt lại vị trí camera
void reset()
{
    eyeX = 0.0;
    eyeY = 0.0;
    eyeZ = 5.0;
    centerX = 0.0;
    centerY = 0.0;
    centerZ = 0.0;
    upX = 0.0;
    upY = 0.1;
    upZ = 0.0;
}

// Hàm xử lý các phím đặc biệt
void SpecialKeys(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
        eyeX = std::max(minEye, eyeX - speed); // Di chuyển vị trí camera sang trái
        break;
    case 'd':
        eyeX = std::min(maxEye, eyeX + speed); // Di chuyển vị trí camera sang phải
        break;
    case 's':
        eyeY = std::max(minEye, eyeY - speed); // Di chuyển vị trí camera xuống dưới
        break;
    case 'w':
        eyeY = std::min(maxEye, eyeY + speed); // Di chuyển vị trí camera lên trên
        break;
    case 'q':
        eyeZ = std::max(minEye, eyeZ - speed); // Di chuyển vị trí camera về phía sau
        break;
    case 'e':
        eyeZ = std::min(maxEye, eyeZ + speed); // Di chuyển vị trí camera về phía trước
        break;
    case 'f':
        centerX = std::max(minCenter, centerX - speed); // Di chuyển điểm nhìn sang trái
        break;
    case 'g':
        centerX = std::min(maxCenter, centerX + speed); // Di chuyển điểm nhìn sang phải
        break;
    case 'h':
        centerY = std::max(minCenter, centerY - speed); // Di chuyển điểm nhìn xuống dưới
        break;
    case 'j':
        centerY = std::min(maxCenter, centerY + speed); // Di chuyển điểm nhìn lên trên
        break;
    case 'k':
        centerZ = std::max(minCenter, centerZ - speed); // Di chuyển điểm nhìn về phía sau
        break;
    case 'l':
        centerZ = std::min(maxCenter, centerZ + speed); // Di chuyển điểm nhìn về phía trước
        break;
    case 'u':
        upX = std::max(minUp, upX - speed); // Di chuyển hướng lên trái
        break;
    case 'i':
        upX = std::min(maxUp, upX + speed); // Di chuyển hướng lên phải
        break;
    case 'o':
        upY = std::max(minUp, upY - speed); // Di chuyển hướng lên xuống
        break;
    case 'p':
        upY = std::min(maxUp, upY + speed); // Di chuyển hướng lên trên
        break;
    case '[':
        upZ = std::max(minUp, upZ - speed); // Di chuyển hướng ngang về sau
        break;
    case ']':
        upZ = std::min(maxUp, upZ + speed); // Di chuyển hướng ngang về trước
        break;
    case 'r':
        reset(); // Đặt lại vị trí camera
        break;
    }
    glutPostRedisplay();
}

/// Hàm main
int main(int argc, char** argv)
{
    // Khởi tạo GLUT và các tham số
    glutInit(&argc, argv);
    // Thiết lập chế độ hiển thị với double buffer, RGB color, và depth buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    // Thiết lập kích thước cửa sổ ban đầu là 800x600
    glutInitWindowSize(800, 600);
    // Tạo cửa sổ với tiêu đề 
    glutCreateWindow("Hinh hop chu nhat-Nhom 11-DHMT");
    // Đăng ký hàm hiển thị (display function) để vẽ hình và các hàm callback khác
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(SpecialKeys);
    // Bật depth testing để vẽ các hình 3D
    glEnable(GL_DEPTH_TEST);
    // Thiết lập ma trận projection (phép chiếu) theo góc nhìn 45 độ, tỷ lệ khung hình 800x600, và khoảng cách gần và xa nhất
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 800.0 / 600.0, 0.1, 100.0);
    // Chuyển sang ma trận modelview để vẽ các đối tượng
    glMatrixMode(GL_MODELVIEW);
    // Vòng lặp chính của GLUT để xử lý sự kiện và hiển thị cửa sổ
    glutMainLoop();
    return 0;
}
