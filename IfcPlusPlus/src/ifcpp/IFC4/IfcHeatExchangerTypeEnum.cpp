/* -*-c++-*- IfcPlusPlus - www.ifcplusplus.com - Copyright (C) 2011 Fabian Gerold
*
* This library is open source and may be redistributed and/or modified under  
* the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
* (at your option) any later version.  The full license is in LICENSE file
* included with this distribution, and on the openscenegraph.org website.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
* OpenSceneGraph Public License for more details.
*/

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/shared_ptr.h"
#include "ifcpp/model/IfcPPException.h"
#include "include/IfcHeatExchangerTypeEnum.h"

// TYPE IfcHeatExchangerTypeEnum = ENUMERATION OF	(PLATE	,SHELLANDTUBE	,USERDEFINED	,NOTDEFINED);
IfcHeatExchangerTypeEnum::IfcHeatExchangerTypeEnum() {}
IfcHeatExchangerTypeEnum::~IfcHeatExchangerTypeEnum() {}
shared_ptr<IfcPPObject> IfcHeatExchangerTypeEnum::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcHeatExchangerTypeEnum> copy_self( new IfcHeatExchangerTypeEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IfcHeatExchangerTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCHEATEXCHANGERTYPEENUM("; }
	if( m_enum == ENUM_PLATE )
	{
		stream << ".PLATE.";
	}
	else if( m_enum == ENUM_SHELLANDTUBE )
	{
		stream << ".SHELLANDTUBE.";
	}
	else if( m_enum == ENUM_USERDEFINED )
	{
		stream << ".USERDEFINED.";
	}
	else if( m_enum == ENUM_NOTDEFINED )
	{
		stream << ".NOTDEFINED.";
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IfcHeatExchangerTypeEnum> IfcHeatExchangerTypeEnum::createObjectFromSTEP( const std::wstring& arg )
{
	// read TYPE
	if( arg.compare( L"$" ) == 0 ) { return shared_ptr<IfcHeatExchangerTypeEnum>(); }
	else if( arg.compare( L"*" ) == 0 ) { return shared_ptr<IfcHeatExchangerTypeEnum>(); }
	shared_ptr<IfcHeatExchangerTypeEnum> type_object( new IfcHeatExchangerTypeEnum() );
	if( boost::iequals( arg, L".PLATE." ) )
	{
		type_object->m_enum = IfcHeatExchangerTypeEnum::ENUM_PLATE;
	}
	else if( boost::iequals( arg, L".SHELLANDTUBE." ) )
	{
		type_object->m_enum = IfcHeatExchangerTypeEnum::ENUM_SHELLANDTUBE;
	}
	else if( boost::iequals( arg, L".USERDEFINED." ) )
	{
		type_object->m_enum = IfcHeatExchangerTypeEnum::ENUM_USERDEFINED;
	}
	else if( boost::iequals( arg, L".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcHeatExchangerTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
