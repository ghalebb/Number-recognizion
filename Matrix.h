// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H

#define INDEX i * dims.cols + j

#include <iostream>

using std::istream;
using std::ifstream;
using std::cout;
using std::endl;


/**
 * @struct MatrixDims
 * @brief Matrix dimensions container
 */
typedef struct MatrixDims
{
	int rows, cols;
} MatrixDims;

/**
 * @class Matrix
 * @brief Matrix header file
 */
class Matrix
{
public:

	/** @brief Matrix constructor
	 * @return Matrix object
	 * */
	Matrix(int rows, int cols);

	/** @brief Matrix default constructor
	 * @return Matrix object
	 * */
	Matrix();

	/** @brief copy constructor
	 * @return Matrix object
	 * */
	Matrix(const Matrix &m);

	/** @brief Matrix destructor frees allocations */
	~Matrix();

	/** @brief matrix rows size getter */
	int getRows() const
	{
		return dims.rows;
	}

	/** @brief matrix cols size getter*/
	int getCols() const
	{
		return dims.cols;
	}

	/** @brief vectorize the matrix
	 * @return one col matrix
	 * */
	Matrix &vectorize();

	/** @brief printing the current Matrix */
	void plainPrint() const;

	/** @overload the = operator*/
	Matrix &operator=(const Matrix &b);

	/** @overload the * operator for two matrices*/
	Matrix operator*(const Matrix &b) const;

	/** @overload the * operator for scalar multiplication*/
	Matrix operator*(float c) const;

	/** @overload the + operator for two matrices*/
	Matrix operator+(const Matrix &b) const;

	/** @overload the += operator */
	Matrix &operator+=(const Matrix &b);

	/** @overload the () operator, and indexing the matrix */
	float &operator()(int i, int j);

	/** @overload the () operator, and indexing the matrix */
	const float &operator()(int i, int j) const;

	/** @overload the [] operator, and indexing the matrix */
	float &operator[](int i);

	/** @overload the [] operator, and indexing the matrix */
	const float &operator[](int i) const;

	/** @overload the >> operator and getting input */
	friend istream &operator>>(istream &is, Matrix &m);

	/** @overload the << operator and returning output */
	friend std::ostream &operator<<(std::ostream &os, Matrix mtx);

	/** @overload the * operator with scalar from the left */
	friend Matrix operator*(const float c, const Matrix &m);

private:
	float *mtx;
	MatrixDims dims{};
};

#endif //MATRIX_H
