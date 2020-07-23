#pragma once

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

template<class Temp>
class MovieManager
{
	Temp** m_pData;
	int m_nChannels;
	int m_nRows, m_nCols;

public:
	MovieManager() :m_pData(NULL), m_nChannels(1), m_nRows(0), m_nCols(0) {}
	~MovieManager() { if (m_pData) delete[] m_pData; }

	// OpenCV Mat 연동 (메모리 공유)
	void Attach(const cv::Mat& m);
	MovieManager(const cv::Mat& m) :m_pData(NULL), m_nChannels(1), m_nRows(0), m_nCols(0) { Attach(m); }
	const MovieManager& operator =(const cv::Mat& m) { Attach(m); return *this; }

	// 행(row) 반환
	Temp* GetPtr(int r)
	{
		assert(r >= 0 && r < m_nRows); return m_pData[r];
	}

	// 연산자 중첩 (원소접근) -- 2D
	Temp* operator [](int r)
	{
		assert(r >= 0 && r < m_nRows); return m_pData[r];
	}

	const Temp* operator [](int r) const
	{
		assert(r >= 0 && r < m_nRows); return m_pData[r];
	}

	// 연산자 중첩 (원소접근) -- 3D
	Temp& operator ()(int r, int c, int k)
	{
		assert(r >= 0 && r < m_nRows&& c >= 0 && c < m_nCols&& k >= 0 && k < m_nChannels); return m_pData[r][c * m_nChannels + k];
	}

	const Temp operator ()(int r, int c, int k) const
	{
		assert(r >= 0 && r < m_nRows&& c >= 0 && c < m_nCols&& k >= 0 && k < m_nChannels); return m_pData[r][c * m_nChannels + k];
	}
};

template<class Temp>
void MovieManager<Temp>::Attach(const cv::Mat& m)
{
	assert(sizeof(Temp) == m.elemSize1());

	m_nChannels = m.channels();
	m_nRows = m.rows;
	m_nCols = m.cols;

	if (m_pData) delete[] m_pData;
	m_pData = new Temp * [m_nRows];
	for (int r = 0; r < m_nRows; r++)
	{
		m_pData[r] = (Temp*)(m.data + r * m.step);
	}
}
