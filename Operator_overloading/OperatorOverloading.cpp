#include<iostream>
//en means entered :)
namespace Two_D
{
	class V_vector;
	class H_vector;
	class Matrix
	{
	public:
		float row1[2], row2[2];
	public:
		Matrix()
		{
			row1[0] = 1, row1[1] = 0;
			row2[0] = 0, row2[1] = 1;
		}
		Matrix(float en_row1[2], float en_row2[2])
		{
			row1[0] = en_row1[0], row1[1] = en_row1[1];
			row2[0] = en_row2[0], row2[1] = en_row2[1];
		}
		Matrix transpose(const Matrix en)
		{
			float newrow1[2] = {en.row1[0], en.row2[0]};
			float newrow2[2] = {en.row1[1], en.row2[1]};
			return Matrix(newrow1, newrow2);
		}//it could be written with void but I like this, it's more fanacy you know:)

		Matrix operator+(const Matrix en)
		{
			float newrow1[2] = {en.row1[0]+row1[0], en.row1[1]+row1[1]};
			float newrow2[2] = {en.row2[0]+row2[1], en.row2[1]+row2[1]};
			return Matrix(newrow1, newrow2);
		}

		Matrix operator*(const Matrix en)
		{
			float newrow1[2] = {row1[0]*en.row1[0]+row1[1]*en.row2[0], row1[0]*en.row1[1]+row1[1]*en.row2[1]};
			float newrow2[2] = {row2[0]*en.row1[0]+row2[1]*en.row2[0], row2[0]*en.row1[1]+row2[1]*en.row2[1]};
			return Matrix(newrow1, newrow2);
		}
		H_vector operator*(const H_vector en);
		
		//~Matrix();
		
	};

	class H_vector
	{
	public:
		float num1, num2;
	public:
		H_vector():num1(0), num2(0){}
		H_vector(float en_num1, float en_num2):num1(en_num1), num2(en_num2){}
		//~H_vector();

		H_vector operator+(const H_vector en)
		{
			return H_vector(num1+en.num1, num2+en.num2);
		}
		
		float operator*(const V_vector en);
		
	};

	class V_vector
	{
	public:
		float num1, num2;
	public:
		V_vector():num1(0), num2(0){}
		V_vector(float en_num1, float en_num2):num1(en_num1), num2(en_num2){}
		//~V_vector();	

		V_vector operator+(const V_vector en)
		{
			return V_vector(num1+en.num1, num2+en.num2);
		}
		V_vector operator*(const H_vector en)
		{
			return V_vector(num1*en.num1, num2*en.num2);
		}
		V_vector operator*(const Matrix en)
		{
			return V_vector(num1*en.row1[0] + num2*en.row2[0], num1*en.row1[1] + num2*en.row2[1]);
		}
	};

	float H_vector::operator*(const V_vector en) //it's dot product:)
	{
		return num1*en.num1+num2*en.num2;
	}

	H_vector Matrix::operator*(const H_vector en)
	{
		float newnum1 = row1[0]*en.num1+row1[1]*en.num2; 
		float newnum2 = row2[0]*en.num1+row2[1]*en.num2;
		return Two_D::H_vector(newnum1, newnum2);
	}

}


namespace Multi_D
{
	class Matrix
	{
		float **head;
		Matrix(int row_num,int column_num)
		{
			head = new float*[row_num];
			for (int i = 0; i < row_num; ++i)
			{
				head[i] = new float[column_num];
			}
		}

	};
	//still working on it:)
}


std::ostream& operator<<(std::ostream& stream, const Two_D::Matrix en)
{
	stream<<en.row1[0]<<" "<<en.row1[1]<<'\n'<<en.row2[0]<<" "<<en.row2[1]<<'\n';
}
std::ostream& operator<<(std::ostream& stream, const Two_D::V_vector en)
{
	stream<<'('<<en.num1<<","<<en.num2<<')'<<'\n';
}
std::ostream& operator<<(std::ostream& stream, const Two_D::H_vector en)
{
	stream<<en.num1<<'\n'<<en.num2<<'\n';
}
int main()
{
	
	float r1[2] = {1, 2}, r2[2] = {3, 4};
	Two_D::Matrix Mat; 
	Two_D::Matrix Matr(r1, r2); 
	Two_D::Matrix product = Mat*Matr;
	std::cout<<product;
	Two_D::V_vector v(1, 2);
	std::cout<<v;
	Two_D::H_vector h(1, 2);
	Two_D::H_vector p = Matr*h;
	std::cout<<p;

	return 0;
}