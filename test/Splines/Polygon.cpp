//
//  Polygon.cpp
//  This file is part of the "Splines" project and released under the MIT License.
//
//  Created by Samuel Williams on 10/6/2020.
//  Copyright, 2020, by Samuel Williams. All rights reserved.
//

#include <UnitTest/UnitTest.hpp>

#include <Splines/Polygon.hpp>

namespace Splines
{
	using namespace UnitTest::Expectations;
	
	UnitTest::Suite PolygonTestSuite {
		"Splines::Polygon",
		
		{"it can generate closed loop",
			[](UnitTest::Examiner & examiner) {
				using Point = Polygon<2>::Point;
				
				Polygon<2> polygon({
					{0, 0}, {1, 0}, {0, 1}
				});
				
				examiner.expect(polygon[-1]).to(be == Point{0, 1});
				examiner.expect(polygon[0]).to(be == Point{0, 0});
				examiner.expect(polygon[1]).to(be == Point{1, 0});
				examiner.expect(polygon[2]).to(be == Point{0, 1});
				examiner.expect(polygon[3]).to(be == Point{0, 0});
			}
		},
	};
}
