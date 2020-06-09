//
//  HermiteSpline.cpp
//  This file is part of the "Splines" project and released under the MIT License.
//
//  Created by Samuel Williams on 10/6/2020.
//  Copyright, 2020, by Samuel Williams. All rights reserved.
//

#include "HermiteSpline.hpp"

namespace Splines
{
	template class HermiteSpline<Polyline<2>>;
	template class HermiteSpline<Polyline<3>>;
}
