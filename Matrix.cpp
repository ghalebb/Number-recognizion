//
// Created by galeb on 11/06/2020.
//

#include "Matrix.h"

#define ADD_ERR "Error: Matrices should be the same size"
#define INDEX_ERR "Error: index is invalid"
#define DBL_ASTERISK "**"
#define DBL_SPACE "  "
#define FILE_ERR "Error: in reading file"
#define DEFAULT_VAL 1
#define DIMENSION_ERR "Error: Matrix dimension are wrong"

/** @brief Matrix constructor
* @return Matrix object
* */
Matrix::Matrix(int rows, int cols) : dims({rows, cols})
{
	if (dims.rows <= 0 || dims.cols <= 0)
	{
		std::cerr << DIMENSION_ERR << endl;
		exit(EXIT_FAILURE);
	}
	mtx = new float[dims.rows * dims.cols];


	for (int i = 0; i < dims.rows; ++i)
	{
		for (int j = 0; j < dims.cols; ++j)
		{
			mtx[i * dims.cols + j] = 0.0f;
		}
	}

}

/** @brief Matrix default constructor
* @return Matrix object
* */
Matrix::Matrix() :
		Matrix(DEFAULT_VAL, DEFAULT_VAL)
{}

/** @brief copy constructor
* @return Matrix object
* */
Matrix::Matrix(const Matrix &m) : dims({m.dims.rows, m.dims.cols})
{
	mtx = new float[dims.rows * dims.cols];
	for (int i = 0; i < dims.rows; ++i)
	{
		for (int j = 0; j < dims.cols; ++j)
		{
			mtx[INDEX] = m.mtx[INDEX];
		}
	}
}

/** @brief vectorize the matrix
* @return one col matrix
* */
Matrix &Matrix::vectorize()
{
	dims.rows = dims.rows * dims.cols;
	dims.cols = 1;
	return *this;
}

/** @brief printing the current Matrix */
void Matrix::plainPrint() const
{
	for (int i = 0; i < dims.rows; i++)
	{
		for (int j = 0; j < dims.cols; j++)
		{
			cout << mtx[INDEX] << " ";
		}
		cout << endl;
	}
}

/** @overload the * operator for two matrices*/
Matrix Matrix::operator*(const Matrix &b) const
{

	if (dims.cols != b.dims.rows)
	{
		std::cerr << DIMENSION_ERR << endl;
		exit(EXIT_FAILURE);
	}
	Matrix newMtx = Matrix(dims.rows, b.dims.cols);
	for (int i = 0; i < this->dims.rows; ++i)
	{
		for (int j = 0; j < b.dims.cols; ++j)
		{
			for (int inner = 0; inner < this->dims.cols; ++inner)
			{
				newMtx[i * b.dims.cols + j] += (*this)(i, inner) * b(inner, j);
			}
		}
	}
	return newMtx;
}

/** @overload the * operator for scalar multiplication*/
Matrix Matrix::operator*(const float c) const
{
	Matrix newMtx = Matrix(dims.rows, dims.cols);

	for (int i = 0; i < dims.rows; i++)
	{
		for (int j = 0; j < dims.cols; j++)
		{
			newMtx(i, j) = (*this)(i, j) * c;
		}
	}
	return newMtx;
}

/** @overload the + operator for two matrices*/
Matrix Matrix::operator+(const Matrix &b) const
{
	if (dims.rows != b.dims.rows || dims.cols != b.dims.cols)
	{
		std::cerr << ADD_ERR << endl;
		exit(EXIT_FAILURE);
	}

	Matrix sum = Matrix(dims.rows, dims.cols);
	for (int i = 0; i < dims.rows; ++i)
	{
		for (int j = 0; j < dims.cols; ++j)
		{
			sum.mtx[i * dims.cols + j] = mtx[i * dims.cols + j] + b.mtx[i * dims.cols + j];
		}
	}
	return sum;
}

/** @overload the += operator */
Matrix &Matrix::operator+=(const Matrix &b)
{
	if (dims.rows != b.dims.rows || dims.cols != b.dims.cols)
	{
		std::cerr << ADD_ERR << endl;
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < dims.rows; i++)
	{
		for (int j = 0; j < dims.cols; ++j)
		{
			mtx[i * dims.cols + j] += b.mtx[i * dims.cols + j];
		}
	}
	return *this;
}

/** @overload the () operator, and indexing the matrix */
float &Matrix::operator()(int i, int j)
{
	if (i < 0 || i >= dims.rows || j < 0 || j >= dims.cols)
	{
		std::cerr << INDEX_ERR << endl;
		exit(EXIT_FAILURE);
	}
	return mtx[i * dims.cols + j];
}

/** @overload the () operator, and indexing the matrix */
const float &Matrix::operator()(int i, int j) const
{
	if (i < 0 || i >= dims.rows || j < 0 || j >= dims.cols)
	{
		std::cerr << INDEX_ERR << endl;
		exit(EXIT_FAILURE);
	}
	return mtx[i * dims.cols + j];
}

/** @overload the [] operator, and indexing the matrix */
float &Matrix::operator[](int i)
{
	if (i < 0 || i >= dims.rows * dims.cols)
	{
		std::cerr << INDEX_ERR << endl;
		exit(EXIT_FAILURE);
	}
	return mtx[i];
}

/** @overload the [] operator, and indexing the matrix */
const float &Matrix::operator[](int i) const
{
	if (i < 0 || i >= dims.rows * dims.cols)
	{
		std::cerr << INDEX_ERR << endl;
		exit(EXIT_FAILURE);
	}
	return mtx[i];
}

/** @brief Matrix destructor frees allocations */
Matrix::~Matrix()
{
	delete[] mtx;
}

/** @overload the >> operator and getting input */
istream &operator>>(istream &is, Matrix &m)
{
	for (int i = 0; i < m.dims.rows; i++)
	{
		for (int j = 0; j < m.getCols(); ++j)
		{
			is.read((char *) &(m.mtx[i * m.dims.cols + j]), sizeof(float));
			if (!is.good())
			{
				std::cerr << FILE_ERR << endl;
				exit(EXIT_FAILURE);
			}
		}
	}
	if (is.peek() != EOF)
	{
		std::cerr << FILE_ERR << endl;
		exit(EXIT_FAILURE);
	}

	return is;
}

/** @overload the << operator and returning output */
std::ostream &operator<<(std::ostream &os, Matrix mtx)
{
	for (int i = 0; i < mtx.dims.rows; ++i)
	{
		for (int j = 0; j < mtx.dims.cols; ++j)
		{
			if (mtx(i, j) <= 0.1f)
			{
				os << DBL_SPACE;
			}
			else
			{
				os << DBL_ASTERISK;
			}
		}
		os << endl;
	}
	return os;
}

/** @overload the = operator*/
Matrix &Matrix::operator=(const Matrix &b)
{
	dims.rows = b.dims.rows;
	dims.cols = b.dims.cols;

	delete[] mtx;

	this->mtx = new float[dims.rows * dims.cols];

	for (int i = 0; i < dims.rows; ++i)
	{
		for (int j = 0; j < dims.cols; ++j)
		{
			mtx[i * dims.cols + j] = b[i * b.dims.cols + j];
		}
	}
	return *this;
}

/** @overload the * operator with scalar from the left */
Matrix operator*(const float c, const Matrix &m)
{
	return m * c;
}











