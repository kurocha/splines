//
//  Polyline.cpp
//  This file is part of the "Splines" project and released under the MIT License.
//
//  Created by Samuel Williams on 9/6/2020.
//  Copyright, 2020, by Samuel Williams. All rights reserved.
//

#include <UnitTest/UnitTest.hpp>

#include <Splines/Polyline.hpp>

namespace Splines
{
	using namespace UnitTest::Expectations;
	
	UnitTest::Suite PolylineTestSuite {
		"Splines::Polyline",
		
		{"it can generate an open line",
			[](UnitTest::Examiner & examiner) {
				using Point = Polyline<2>::Point;
				
				Polyline<2> polyline({
					{0, 0}, {1, 0}, {0, 1}
				});
				
				examiner.expect(polyline[-1]).to(be == Point{0, 0});
				examiner.expect(polyline[0]).to(be == Point{0, 0});
				examiner.expect(polyline[1]).to(be == Point{1, 0});
				examiner.expect(polyline[2]).to(be == Point{0, 1});
				examiner.expect(polyline[3]).to(be == Point{0, 1});
			}
		},
	};
}
