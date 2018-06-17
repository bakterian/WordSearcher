#include "stdafx.h"
#include "NodeHelperTests.h"


NodeHelperTests::NodeHelperTests():
	m_head(20)
{

}

NodeHelperTests::~NodeHelperTests() {};

void NodeHelperTests::SetUp() {};

void NodeHelperTests::TearDown() {};

TEST_F(NodeHelperTests, NodeCheck)
{
	auto initialItem = m_head.Item;
	auto linkedItem = m_head.NextNode;

	ASSERT_EQ(20, initialItem);
	ASSERT_EQ(nullptr, linkedItem);
}

TEST_F(NodeHelperTests, ShouldAddNewNodes)
{
	int newItems[] = { 30,40,50 };

	for (size_t i = 0; i < 3; i++)
	{
		m_nodeHelper.AppendToBack(m_head, newItems[i]);
	}

	EXPECT_EQ(20, m_head.Item);
	auto node = m_head.NextNode;
	for (size_t i = 0; i < 3; i++)
	{
		ASSERT_NE(nullptr, node);
		EXPECT_EQ(newItems[i], node->Item);
		node = node->NextNode;
	}

	ASSERT_EQ(nullptr, node);
}

TEST_F(NodeHelperTests, ShouldReturnProperListSize)
{
	auto expectedListSize = 10;

	for (int i = 0; i < (expectedListSize-1); i++)
	{
		auto randNumber = rand() % 100 + 1;

		m_nodeHelper.AppendToBack(m_head, randNumber);
	}

	auto actualSize = m_nodeHelper.GetListSize(m_head);

	ASSERT_EQ(expectedListSize, actualSize);
}