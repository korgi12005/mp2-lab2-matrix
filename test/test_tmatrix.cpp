#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> v(10);
	TMatrix<int> v1(v);
	EXPECT_EQ(v1, v);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> v(10);
	TMatrix<int> v1(v);
	v1[0][0] = 4;
	EXPECT_NE(v1, v);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> v(4);
	v[0][0] = 4;

	EXPECT_EQ(4, v[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> V1(5);
	ASSERT_ANY_THROW(V1[-1][-1] = 0);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> V1(5);
	ASSERT_ANY_THROW(V1[6][4] = 0);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> V1(5);
	
	ASSERT_NO_THROW(V1 = V1);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> V1(5), V2(5);
	V1 = V2;
	EXPECT_EQ(V1, V2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> V1(5), V2(2);
	V1 = V2;
	EXPECT_EQ(V1, V2);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> V1(5), V2(2);

	ASSERT_NO_THROW(V1 = V2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> V1(5);
	TMatrix<int> V2(5);
	EXPECT_EQ(V1, V2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> V1(5);
	
	EXPECT_EQ(V1, V1);
}


TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> V1(5);
	TMatrix<int> V2(6);
	EXPECT_NE(V1, V2);

}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> V1(5), V2(5), V3(5);
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++) {
			V1[i][j] = 1;
			V2[i][j] = 2;
			V3[i][j] = 3;
		}

	V1 = V1 + V2;
	EXPECT_EQ(V1 , V3);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> V1(5), V2(7), V3(7);
	ASSERT_ANY_THROW(V3 = V2 + V1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> V1(5), V2(5), V3(5);
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++) {
			V1[i][j] = 1;
			V2[i][j] = 2;
			V3[i][j] = 3;
		}

	V3 = V3- V2;
	EXPECT_EQ(V1, V3);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> V1(5), V2(7), V3(7);
	ASSERT_ANY_THROW(V3 = V2 - V1);
}

