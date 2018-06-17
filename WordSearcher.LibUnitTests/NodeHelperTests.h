#pragma once
#include "Node.h"
#include "NodeHelper.h"
#include "gtest/gtest.h"

class NodeHelperTests : public ::testing::Test
{
public:
	Node<int> m_head;

	NodeHelper m_nodeHelper;

	NodeHelperTests();

	virtual ~NodeHelperTests();

	virtual void SetUp();

	virtual void TearDown();
};

