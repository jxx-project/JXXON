//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/UnorderedMultiset.h"
#include "Testee/setTest.h"

int main(int argc, char* argv[])
{
	return Testee::setTest<JXXON::UnorderedMultiset, true>("JXXON::UnorderedMultiset");
}
