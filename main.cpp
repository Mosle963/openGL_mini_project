#include <GL/glut.h>
#include <iostream>
#include <vector>
using namespace std;
const float win_width = 700;
const float win_height = 700;

int shapes_counter = 0;
int shape_number = 1;
float col1 = 0.0, col2 = 1.0, col3 = 0.0;
float rotate_array[1000];
float scale_array[1000];
float translete_array[1000];

class Triangle {
public:
	int id;
	float cx = 0.0;
	float cy = 0.0;

	void draw()
	{
		float half_len = 0.1;
		glLoadIdentity();
		glTranslatef(cx + translete_array[id], cy, 0.0);
		glRotatef(rotate_array[id], 0.0, 0.0, 1.0);
		glScalef(scale_array[id], scale_array[id], 1.0);
		//drawing part
		glBegin(GL_TRIANGLES);
		glColor4f(col1, col2, col3, 1.0);
		glVertex3f(-half_len, -half_len / 2, 0.0);
		glVertex3f(0.0, half_len, 0.0);
		glVertex3f(half_len, -half_len / 2, 0.0);
		glEnd();
	}
};
class Square
{
public:
	int id;
	float cx = 0.0;
	float cy = 0.0;

	void draw()
	{
		float half_len = 0.1;
		glLoadIdentity();
		glTranslatef(cx + translete_array[id], cy, 0.0);
		glRotatef(rotate_array[id], 0.0, 0.0, 1.0);
		glScalef(scale_array[id], scale_array[id], 1.0);
		//drawing part
		glBegin(GL_TRIANGLES);
		glColor4f(col1, col2, col3, 1.0);
		glVertex3f(-half_len, -half_len, 0.0);
		glVertex3f(-half_len, half_len, 0.0);
		glVertex3f(half_len, -half_len, 0.0);
		glEnd();
		glBegin(GL_TRIANGLES);
		glColor4f(col1, col2, col3, 1.0);
		glVertex3f(-half_len, half_len, 0.0);
		glVertex3f(half_len, -half_len, 0.0);
		glVertex3f(half_len, half_len, 0.0);
		glEnd();
	}
};
class Pentagon
{
public:
	int id;
	float cx = 0.0;
	float cy = 0.0;

	void draw()
	{
		float r = 0.15;
		int n_of_tri = 5;
		float past_theta = 0.0;
		for (int i = 1; i <= n_of_tri; i++)
		{

			float theta = float(i) * 2.0f * 3.145f / float(n_of_tri);
			float past_x = r * cosf(past_theta);
			float past_y = r * sinf(past_theta);
			float x = r * cosf(theta);
			float y = r * sinf(theta);
			glLoadIdentity();
			glTranslatef(cx + translete_array[id], cy, 0.0);
			glRotatef(rotate_array[id], 0.0, 0.0, 1.0);
			glScalef(scale_array[id], scale_array[id], 1.0);
			//drawing part
			glBegin(GL_TRIANGLES);
			float color_adjust = float(i % 2) + 1.0;
			glColor4f(col1 / color_adjust, col2 / color_adjust, col3 / color_adjust, 1.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f((past_x), past_y, 0.0);
			glVertex3f(x, y, 0.0);
			glEnd();
			past_theta = theta;
		}

	}

};
class Circle
{
public:
	int id;
	float cx = 0.0;
	float cy = 0.0;

	void draw()
	{
		float r = 0.15;
		int n_of_tri = 50;
		float past_theta = 0.0;
		for (int i = 1; i <= n_of_tri; i++)
		{
			float theta = float(i) * 2.0f * 3.145f / float(n_of_tri);
			float past_x = r * cosf(past_theta);
			float past_y = r * sinf(past_theta);
			float x = r * cosf(theta);
			float y = r * sinf(theta);
			glLoadIdentity();
			glTranslatef(cx + translete_array[id], cy, 0.0);
			glRotatef(rotate_array[id], 0.0, 0.0, 1.0);
			glScalef(scale_array[id], scale_array[id], 1.0);
			//drawing part
			glBegin(GL_TRIANGLES);
			if (i % 5) { glColor4f(col1, col2, col3, 1.0); }
			else { glColor4f(col1 * 0.9, col2 * 0.9, col3 * 0.9, 1.0); }
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(past_x, past_y, 0.0);
			glVertex3f(x, y, 0.0);
			glEnd();
			past_theta = theta;
		}
	}
};
class Cube
{
public:
	int id;
	float cx = 0.0;
	float cy = 0.0;

	void draw()
	{
		float cube_ver = 0.10;
		float cube_x = cube_ver;
		float cube_y = cube_ver;
		float cube_z = cube_ver;
		glLoadIdentity();
		glTranslatef(cx + translete_array[id], cy, 0.0);
		glRotatef(rotate_array[id] + 45.0, 1.0, 1.0, 1.0);
		glScalef(scale_array[id], scale_array[id], scale_array[id]);

		//drawing part
		// Back
		glBegin(GL_POLYGON);
		glColor3f(col1, col2, col3);
		glVertex3f(-cube_x, -cube_y, -cube_z);       // P1
		glVertex3f(-cube_x, cube_y, -cube_z);       // P2
		glVertex3f(cube_x, cube_y, -cube_z);       // P3
		glVertex3f(cube_x, -cube_y, -cube_z);       // P4
		glEnd();

		// Front
		glBegin(GL_POLYGON);
		glColor3f(col1, col2, col3);
		glVertex3f(-cube_x, -cube_y, cube_z);
		glVertex3f(-cube_x, cube_y, cube_z);
		glVertex3f(cube_x, cube_y, cube_z);
		glVertex3f(cube_x, -cube_y, cube_z);
		glEnd();

		// RIGHT
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(cube_x, -cube_y, -cube_z);
		glVertex3f(cube_x, cube_y, -cube_z);
		glVertex3f(cube_x, cube_y, cube_z);
		glVertex3f(cube_x, -cube_y, cube_z);
		glEnd();

		// LEFT
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-cube_x, -cube_y, cube_z);
		glVertex3f(-cube_x, cube_y, cube_z);
		glVertex3f(-cube_x, cube_y, -cube_z);
		glVertex3f(-cube_x, -cube_y, -cube_z);
		glEnd();

		// TOP
		glBegin(GL_POLYGON);
		glColor3f(col1 / 6.0f, col2 / 6.0f, col3 / 6.0f);
		glVertex3f(cube_x, cube_y, cube_z);
		glVertex3f(cube_x, cube_y, -cube_z);
		glVertex3f(-cube_x, cube_y, -cube_z);
		glVertex3f(-cube_x, cube_y, cube_z);
		glEnd();

		// BOTTOM
		glBegin(GL_POLYGON);
		glColor3f(col1 / 6.0f, col2 / 6.0f, col3 / 6.0f);
		glVertex3f(cube_x, -cube_y, -cube_z);
		glVertex3f(cube_x, -cube_y, cube_z);
		glVertex3f(-cube_x, -cube_y, cube_z);
		glVertex3f(-cube_x, -cube_y, -cube_z);
		glEnd();

	}
};
class Sphare
{
public:
	int id;
	float cx = 0.0;
	float cy = 0.0;
	void draw()
	{
		double r = 0.15;
		int lats = 50;
		int longs = 50;
		for (int i = 0; i <= lats; i++) {
			double lat0 = 3.145 * (-0.5 + (double)(i - 1) / lats);
			double z0 = sin(lat0);
			double zr0 = cos(lat0);

			double lat1 = 3.145 * (-0.5 + (double)i / lats);
			double z1 = sin(lat1);
			double zr1 = cos(lat1);

			glLoadIdentity();
			glTranslatef(cx + translete_array[id], cy, 0.0);
			glRotatef(rotate_array[id] + 45.0, 1.0, 1.0, 1.0);
			glScalef(scale_array[id], scale_array[id], scale_array[id]);
			//drawing part
			glBegin(GL_QUAD_STRIP);
			for (int j = 0; j <= longs; j++) {
				double lng = 2 * 3.145 * (double)(j - 1) / longs;
				double x = cos(lng);
				double y = sin(lng);
				if (j % 5) { glColor3f(col1, col2, col3); }
				else { glColor3f(1.0, 1.0, 1.0); }

				glNormal3f(x * zr0, y * zr0, z0);
				glVertex3f(r * x * zr0, r * y * zr0, r * z0);
				glNormal3f(x * zr1, y * zr1, z1);
				glVertex3f(r * x * zr1, r * y * zr1, r * z1);
			}
			glEnd();

		}
	}
};

vector<Triangle> Triangles;
vector<Square> Squares;
vector<Pentagon> Pentagons;
vector<Circle> Circles;
vector<Cube> Cubes;
vector<Sphare> Sphares;

void fixed_size(int w, int h);
void DISPLAY(void);
void add_shabe(int shape, float x, float y);
void translete_all(float val);
void scale_all(float val);
void rotate_all(float val);
void Mouse(int button, int state, int x, int y);
void Keys(unsigned char ch, int x, int y);
void menu(int value);
void create_menu();

int main(int argc, char** argv)
{
	cout << "Please make sure your input language is English!!" << endl;
	cout << "Press 1 to draw A Triangle" << endl;
	cout << "Press 2 to draw A Square" << endl;
	cout << "Press 3 to draw A Pentagon" << endl;
	cout << "Press 4 to draw A Circle" << endl;
	cout << "Press 5 to draw A Cube" << endl;
	cout << "Press 6 to draw A Spahare(Ball)" << endl << endl;;
	cout << "Press 0 to reset the screen" << endl;
	cout << "Press r (lower Case) to rotate all shapes 45 degree clockwise" << endl;
	cout << "Press R (Upper Case) to rotate all shapes 45 degree counterclockwise" << endl;
	cout << "Press t (lower Case) to translete all shapes 10 steps to the right" << endl;
	cout << "Press T (Upper Case) to translete all shapes 10 steps to the left" << endl;
	cout << "Press s (lower Case) to make the size of the shapes twice as it is" << endl;
	cout << "Press S (Upper Case) to make the size of the shapes half of the orignal one" << endl << endl;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(win_width, win_height);
	glutCreateWindow("mohammad_167819_rami_134396");
	glEnable(GL_DEPTH_TEST);
	glutReshapeFunc(fixed_size);
	glutKeyboardFunc(Keys);
	glutMouseFunc(Mouse);
	create_menu();
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(DISPLAY);
	glutMainLoop();
	return 1;
}

void fixed_size(int w, int h)
{
	glutReshapeWindow(win_width, win_height);
	glutPostRedisplay();

}
void DISPLAY(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < Triangles.size(); i++)
	{
		Triangles[i].draw();
	}

	for (int i = 0; i < Squares.size(); i++)
	{
		Squares[i].draw();
	}

	for (int i = 0; i < Pentagons.size(); i++)
	{
		Pentagons[i].draw();
	}

	for (int i = 0; i < Circles.size(); i++)
	{
		Circles[i].draw();
	}

	for (int i = 0; i < Cubes.size(); i++)
	{
		Cubes[i].draw();
	}

	for (int i = 0; i < Sphares.size(); i++)
	{
		Sphares[i].draw();
	}

	glFlush();
	glutSwapBuffers();
}
void add_shabe(int shape, float x, float y)
{
	if (shape == 1)
	{
		Triangle new_Triangle = Triangle();
		rotate_array[shapes_counter] = 0.0;
		scale_array[shapes_counter] = 1.0;
		translete_array[shapes_counter] = 0.0;
		new_Triangle.id = shapes_counter;
		new_Triangle.cx = x;
		new_Triangle.cy = y;

		Triangles.push_back(new_Triangle);
	}
	if (shape == 2)
	{
		Square new_Square = Square();
		rotate_array[shapes_counter] = 0.0;
		scale_array[shapes_counter] = 1.0;
		translete_array[shapes_counter] = 0.0;
		new_Square.id = shapes_counter;
		new_Square.cx = x;
		new_Square.cy = y;

		Squares.push_back(new_Square);
	}
	if (shape == 3)
	{
		Pentagon new_Pentagon = Pentagon();
		rotate_array[shapes_counter] = 0.0;
		scale_array[shapes_counter] = 1.0;
		translete_array[shapes_counter] = 0.0;
		new_Pentagon.id = shapes_counter;
		new_Pentagon.cx = x;
		new_Pentagon.cy = y;
		Pentagons.push_back(new_Pentagon);
	}
	if (shape == 4)
	{
		Circle new_Circle = Circle();
		rotate_array[shapes_counter] = 0.0;
		scale_array[shapes_counter] = 1.0;
		translete_array[shapes_counter] = 0.0;
		new_Circle.id = shapes_counter;
		new_Circle.cx = x;
		new_Circle.cy = y;
		Circles.push_back(new_Circle);
	}
	if (shape == 5)
	{
		Cube new_Cube = Cube();
		rotate_array[shapes_counter] = 0.0;
		scale_array[shapes_counter] = 1.0;
		translete_array[shapes_counter] = 0.0;
		new_Cube.id = shapes_counter;
		new_Cube.cx = x;
		new_Cube.cy = y;
		Cubes.push_back(new_Cube);
	}
	if (shape == 6)
	{
		Sphare new_Sphare = Sphare();
		rotate_array[shapes_counter] = 0.0;
		scale_array[shapes_counter] = 1.0;
		translete_array[shapes_counter] = 0.0;
		new_Sphare.id = shapes_counter;
		new_Sphare.cx = x;
		new_Sphare.cy = y;
		Sphares.push_back(new_Sphare);
	}
	glutPostRedisplay();
	shapes_counter++;
}
void translete_all(float val)
{
	for (int i = 0; i < shapes_counter; i++)
	{
		translete_array[i] += val;
	}
	glutPostRedisplay();

}
void rotate_all(float val)
{
	for (int i = 0; i < shapes_counter; i++)
	{
		rotate_array[i] += val;
	}
	glutPostRedisplay();

}
void scale_all(float val)
{
	for (int i = 0; i < shapes_counter; i++)
	{
		scale_array[i] *= val;
	}
	glutPostRedisplay();

}
float make_it_usable_x(float x)
{
	x -= win_width / 2;
	x /= (win_width / 2);
	return x;
}
float make_it_usable_y(float y)
{

	y -= win_width / 2;
	y /= (win_width / 2);
	return -1 * y;

}
void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		float usable_x = make_it_usable_x(float(x));
		float usable_y = make_it_usable_y(float(y));
		add_shabe(shape_number, usable_x, usable_y);
	}



}
void Keys(unsigned char ch, int x, int y)
{
	//  number 0 - reset the screen
	if (ch == 48)
	{
		cout << "the screen have been cleared" << endl;
		shape_number = 1;
		Triangles.clear();
		Squares.clear();
		Pentagons.clear();
		Circles.clear();
		Cubes.clear();
		Sphares.clear();
		shapes_counter = 0;

	}
	//  number 1 - show_Triangle
	if (ch == 49)
	{
		cout << "the next shape will be Triangle" << endl;
		shape_number = 1;
	}
	//  number 2 - show_Square
	if (ch == 50)
	{
		cout << "the next shape will be square" << endl;
		shape_number = 2;
	}
	//  number 3 - show_Pentagon
	if (ch == 51)
	{
		cout << "the next shape will be Pentagon" << endl;
		shape_number = 3;
	}
	//  number 4 - show_Circle
	if (ch == 52)
	{
		cout << "the next shape will be Circle" << endl;
		shape_number = 4;
	}
	//  number 5 - show_Cube
	if (ch == 53)
	{
		cout << "the next shape will be Cube" << endl;
		shape_number = 5;
	}
	//  number 6 - show_Sphare
	if (ch == 54)
	{
		cout << "the next shape will be Sphare" << endl;
		shape_number = 6;
	}
	if (ch == 114)
	{
		rotate_all(45.0);
	}
	if (ch == 82)
	{
		rotate_all(-45.0);
	}
	if (ch == 115)
	{
		scale_all(2.0);
	}
	if (ch == 83)
	{
		scale_all(0.5);
	}
	if (ch == 116)
	{
		translete_all(0.1);
	}

	if (ch == 84)
	{
		translete_all(-0.1);
	}
	//  Request display update
	glutPostRedisplay();
}
void menu(int value)
{
	if (value == 1) { col1 = 1.0; col2 = 0.0; col3 = 0.0; }
	if (value == 2) { col1 = 0.0; col2 = 1.0; col3 = 0.0; }
	if (value == 3) { col1 = 0.0; col2 = 0.0; col3 = 1.0; }
	if (value == 4) { col1 = 1.0; col2 = 0.0; col3 = 1.0; }
	if (value == 5) { col1 = 0.8; col2 = 0.8; col3 = 0.2; }
	glutPostRedisplay();

}
void create_menu() {
	glutCreateMenu(menu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("green", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("Purble", 4);
	glutAddMenuEntry("Yellow", 5);
}