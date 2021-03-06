//
//  CubicSpline.cpp
//  This file is part of the "Splines" project and released under the MIT License.
//
//  Created by Samuel Williams on 9/6/2020.
//  Copyright, 2020, by Samuel Williams. All rights reserved.
//

#include "CubicSpline.hpp"

namespace Splines
{
	template class CubicSpline<Polyline<2>>;
	template class CubicSpline<Polyline<3>>;
}
