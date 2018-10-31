//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Multiset.h"
#include "Testee/setTest.h"

int main(int argc, char* argv[])
{
	return Testee::setTest<JXXON::Multiset, false, true>("JXXON::Multiset");
}
