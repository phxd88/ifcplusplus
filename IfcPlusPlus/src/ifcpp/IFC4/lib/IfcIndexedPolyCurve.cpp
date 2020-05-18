/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcBoolean.h"
#include "ifcpp/IFC4/include/IfcCartesianPointList.h"
#include "ifcpp/IFC4/include/IfcIndexedPolyCurve.h"
#include "ifcpp/IFC4/include/IfcPresentationLayerAssignment.h"
#include "ifcpp/IFC4/include/IfcSegmentIndexSelect.h"
#include "ifcpp/IFC4/include/IfcStyledItem.h"

// ENTITY IfcIndexedPolyCurve 
IfcIndexedPolyCurve::IfcIndexedPolyCurve( int id ) { m_entity_id = id; }
shared_ptr<BuildingObject> IfcIndexedPolyCurve::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcIndexedPolyCurve> copy_self( new IfcIndexedPolyCurve() );
	if( m_Points ) { copy_self->m_Points = dynamic_pointer_cast<IfcCartesianPointList>( m_Points->getDeepCopy(options) ); }
	for( size_t ii=0; ii<m_Segments.size(); ++ii )
	{
		auto item_ii = m_Segments[ii];
		if( item_ii )
		{
			copy_self->m_Segments.emplace_back( dynamic_pointer_cast<IfcSegmentIndexSelect>(item_ii->getDeepCopy(options) ) );
		}
	}
	if( m_SelfIntersect ) { copy_self->m_SelfIntersect = dynamic_pointer_cast<IfcBoolean>( m_SelfIntersect->getDeepCopy(options) ); }
	return copy_self;
}
void IfcIndexedPolyCurve::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCINDEXEDPOLYCURVE" << "(";
	if( m_Points ) { stream << "#" << m_Points->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_Segments.size() > 0 )
	{
		stream << "(";
		for( size_t ii = 0; ii < m_Segments.size(); ++ii )
		{
			if( ii > 0 )
			{
				stream << ",";
			}
			const shared_ptr<IfcSegmentIndexSelect>& type_object = m_Segments[ii];
			if( type_object )
			{
				type_object->getStepParameter( stream, true );
			}
			else
			{
				stream << "$";
			}
		}
		stream << ")";
	}
	else { stream << "$"; }
	stream << ",";
	if( m_SelfIntersect ) { m_SelfIntersect->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcIndexedPolyCurve::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_entity_id; }
const std::wstring IfcIndexedPolyCurve::toString() const { return L"IfcIndexedPolyCurve"; }
void IfcIndexedPolyCurve::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 3 ){ std::stringstream err; err << "Wrong parameter count for entity IfcIndexedPolyCurve, expecting 3, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	readEntityReference( args[0], m_Points, map );
	readSelectList( args[1], m_Segments, map );
	m_SelfIntersect = IfcBoolean::createObjectFromSTEP( args[2], map );
}
void IfcIndexedPolyCurve::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IfcBoundedCurve::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "Points", m_Points ) );
	if( !m_Segments.empty() )
	{
		shared_ptr<AttributeObjectVector> Segments_vec_object( new AttributeObjectVector() );
		std::copy( m_Segments.begin(), m_Segments.end(), std::back_inserter( Segments_vec_object->m_vec ) );
		vec_attributes.emplace_back( std::make_pair( "Segments", Segments_vec_object ) );
	}
	vec_attributes.emplace_back( std::make_pair( "SelfIntersect", m_SelfIntersect ) );
}
void IfcIndexedPolyCurve::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IfcBoundedCurve::getAttributesInverse( vec_attributes_inverse );
}
void IfcIndexedPolyCurve::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcBoundedCurve::setInverseCounterparts( ptr_self_entity );
}
void IfcIndexedPolyCurve::unlinkFromInverseCounterparts()
{
	IfcBoundedCurve::unlinkFromInverseCounterparts();
}
