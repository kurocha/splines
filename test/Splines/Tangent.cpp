//
//  Tangent.cpp
//  This file is part of the "Splines" project and released under the MIT License.
//
//  Created by Samuel Williams on 9/6/2020.
//  Copyright, 2020, by Samuel Williams. All rights reserved.
//

#include <UnitTest/UnitTest.hpp>

#include <Splines/Polyline.hpp>
#include <Splines/Spline.hpp>
#include <Splines/Tangent.hpp>

namespace Splines
{
	using namespace UnitTest::Expectations;
	
	UnitTest::Suite TangentTestSuite {
		"Splines::Tangent",
		
		{"it can calculate tangent",
			[](UnitTest::Examiner & examiner) {
				using Point = Polyline<2>::Point;
				
				Polyline<2> polyline({{0.0, 0.0}, {1.0, 0.0}});
				Spline spline(polyline);
				Tangent tangent(spline);
				
				examiner.expect(spline[0.5]).to(be == Point{0.5, 0.0});
				examiner.expect(tangent[0.5]).to(be == Point{1.0, 0.0});
			}
		},
	};
}
