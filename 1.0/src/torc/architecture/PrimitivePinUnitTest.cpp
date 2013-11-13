// Torc - Copyright 2011-2013 University of Southern California.  All Rights Reserved.
// $HeadURL$
// $Id$

// This program is free software: you can redistribute it and/or modify it under the terms of the 
// GNU General Public License as published by the Free Software Foundation, either version 3 of the 
// License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See 
// the GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License along with this program.  If 
// not, see <http://www.gnu.org/licenses/>.

/// \file
/// \brief Unit test for the PrimitivePin class.

#include <boost/test/unit_test.hpp>
#include "torc/architecture/PrimitivePin.hpp"

namespace torc {
namespace architecture {

BOOST_AUTO_TEST_SUITE(architecture)

/// \brief Unit test for the PrimitivePin class.
BOOST_AUTO_TEST_CASE(PrimitivePinUnitTest) {
	// members tested:
	//		string mName;
	//		PinFlags mFlags;
	// functions tested:
	//		PrimitivePin(const string& inName, PinFlags inFlags);
	//		const string& getName(void) const;
	//		PinFlags getFlags(void) const;
	//		PrimitivePin(void);
	//		bool isInput(void) const;
	//		bool isOutput(void) const;
	std::string name = "name";
	xilinx::PinFlags flags(PinDirection::ePinDirectionOutput);
	PrimitivePin pin1(name, flags);
	BOOST_CHECK_EQUAL(pin1.getName(), name);
	BOOST_CHECK_EQUAL(pin1.getFlags(), flags);
	BOOST_CHECK(pin1.isInput() == false);
	BOOST_CHECK(pin1.isOutput() == true);
	PrimitivePin pin2;
	BOOST_CHECK_EQUAL(pin2.getName(), "");
	BOOST_CHECK_EQUAL(pin2.getFlags(), xilinx::PinFlags(0));
	BOOST_CHECK(pin2.isInput() == false);
	BOOST_CHECK(pin2.isOutput() == false);
}

BOOST_AUTO_TEST_SUITE_END()

} // namespace architecture
} // namespace torc