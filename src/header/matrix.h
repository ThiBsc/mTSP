#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <sstream>

using namespace std;

template<typename T>
class Matrix {

public:
	typedef T value_type;
	typedef vector<T> row_t;
	// ctor
	Matrix(){}	
	Matrix(int rows, int cols){
		for (int i = 0; i<rows; ++i){
			mat.push_back(row_t(cols));
		}
	}
	Matrix(int rows, int cols, const initializer_list<T>& l){
		for (int i = 0; i<rows; ++i){
			mat.push_back(row_t(cols));
		}
		auto it = l.begin();
		int y=0, x=0;
		while (it != l.end()){
			mat[y][x++] = *it++;
			if (x == cols){
				++y;
				x = 0;
			}
		}
	}
	Matrix(const Matrix<T>& m){
		for (auto e : m.mat){
			mat.push_back(e);
		}
	}
	// methode
	ostream& print(ostream& out){
		for (auto row : mat){
			for (auto e : row){
				out << e << " ";
			}
			out << endl;
		}
		return out;
	}
	int getRowCount(){
		return mat.size();
	}

	int getColumnCount(){
		if (mat.size() == 0)
			return 0;
		return mat[0].size();
	}

	row_t& operator[](int n){
		if ( n<0 || static_cast<size_t>(n) >= mat.size() ){
			ostringstream oss;
			oss << "bad index " << n << " out of range [0.." << mat.size() << "]";
			throw runtime_error(oss.str());
		}
		return mat[n];
	}

	void sum(Matrix<T>& a, Matrix<T>& b){
		if ( a.getRowCount() != b.getRowCount()
			|| a.getColumnCount() != b.getColumnCount()){
			throw runtime_error("error in sum: number of rows or columns differs");
		}
		if (getRowCount() != a.getRowCount()
			|| getColumnCount() != a.getColumnCount()){
			mat.clear();
			for (int i=0; i<a.getRowCount(); ++i){
				mat.push_back(row_t(a.getColumnCount()));
			}
		}
		for (int y=0; y < a.getRowCount(); ++y){
			for (int x=0; x<a.getColumnCount(); ++x){
				mat[y][x] = a.mat[y][x] + b.mat[y][x];
			}
		}
	}

	static Matrix<T> prod(Matrix<T>& a, Matrix<T>& b){
		int a_rows = a.getRowCount();
		int a_cols = a.getColumnCount();
		int b_rows = b.getRowCount();
		int b_cols = b.getColumnCount();

		if (a_cols != b_rows){
			throw runtime_error("product error");
		}
		Matrix<int> m(a_rows, b_cols);
		for (int i=0; i<a_rows; ++i){
			for (int j=0; j<b_cols; ++j){
				T s = 0;
				for (int k=0; k<a_cols; ++k){
					s += a[i][k] * b[k][j];
				}
				m[i][j] = s;
			}
		}
		return m;
	}

	Matrix<T>& operator=(const Matrix<T>& m){
		if (&m != this){
			mat.clear();
			for (auto e : m.mat){
				mat.push_back(e);
			}
		}
		return *this;
	}
	Matrix<T> operator+(Matrix<T>& b){
		if ( getRowCount() != b.getRowCount()
			|| getColumnCount() != b.getColumnCount()){
			throw runtime_error("error in sum: number of rows or columns differs");
		}
		Matrix<T> tmp(getRowCount(), getColumnCount());
		for (int y=0; y < getRowCount(); ++y){
			for (int x=0; x<getColumnCount(); ++x){
				tmp[y][x] = mat[y][x] + b.mat[y][x];
			}
		}
		return tmp;
	}
	Matrix<T> operator*(Matrix<T>& b){
		int a_rows = getRowCount();
		int a_cols = getColumnCount();
		int b_rows = b.getRowCount();
		int b_cols = b.getColumnCount();

		if (a_cols != b_rows){
			throw runtime_error("product error");
		}
		Matrix<int> m(a_rows, b_cols);
		for (int i=0; i<a_rows; ++i){
			for (int j=0; j<b_cols; ++j){
				T s = 0;
				for (int k=0; k<a_cols; ++k){
					s += mat[i][k] * b[k][j];
				}
				m[i][j] = s;
			}
		}
		return m;
	}
	Matrix<T>& operator+=(Matrix<T>& b){
		Matrix<T> tmp(getRowCount(), getColumnCount());
		tmp = *this + b;
		*this = tmp;
		return *this;
	}
	Matrix<T>& operator*=(Matrix<T>& b){
		Matrix<T> tmp(getRowCount(), getColumnCount()); 
		tmp = *this * b;
		*this = tmp;
		return *this;
	}
	friend ostream& operator<<(ostream& out, Matrix<T>& m){
		return m.print(out);
	}

private:
	// size_t row, col;
	vector<row_t> mat;

};

#endif // MATRIX_H