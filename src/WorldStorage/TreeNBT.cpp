
#include "Globals.h"

#include "TreeNBT.h"


namespace
{

struct sDestroyer
{
	template <typename T>
	void operator () (T & a_Value)
	{
		a_Value.~T();
	}


	void operator () (TreeNBT::cList & a_Compound)
	{
		delete &a_Compound;
	}
};

}  // namespace (anonymous)



namespace TreeNBT
{

		/** Can the given tag type be added to the list? */
	bool cList::IsTagCompatible(const std::shared_ptr<cTag> a_Tag) const
	{
		return (
			// If there are elements already, they must be of the same type
			m_Tags.empty() || (m_Tags[0]->index() == a_Tag->index()));
	}

// ////////////////////////////////////////////////////////////////////////////////
// // TreeNBT::cTag::cPayload:

// void cTag::cPayload::Construct(cList a_List)
// {
// 	Construct(new cList(std::move(a_List)));
// }





// ////////////////////////////////////////////////////////////////////////////////
// // TreeNBT::cTag:

// void cTag::Destroy()
// {
// 	Visit(sDestroyer{});
// }





// cTag::cTag(const cTag & a_CopyFrom):
// 	m_TagId{a_CopyFrom.m_TagId},
// 	m_Payload{cEmptyTag{}}
// {
// 	a_CopyFrom.Visit(sCopyConstructor{m_Payload});
// }





// cTag::cTag(cTag && a_MoveFrom):
// 	m_TagId{a_MoveFrom.m_TagId},
// 	m_Payload{cEmptyTag{}}
// {
// 	a_MoveFrom.Visit(sMoveConstructor{m_Payload});
// }





// cTag & cTag::operator = (const cTag & a_CopyFrom)
// {
// 	if (m_TagId != a_CopyFrom.m_TagId)
// 	{
// 		// Copy assign different type
// 		Destroy();
// 		m_TagId = a_CopyFrom.m_TagId;

// 		try
// 		{
// 			a_CopyFrom.Visit(sCopyConstructor{m_Payload});
// 		}
// 		catch (...)
// 		{
// 			// We just deleted the old value but the new value failed to construct
// 			// Tag as empty to avoid double deletion
// 			m_TagId = TAG_End;
// 			m_Payload.Construct(cEmptyTag{});
// 			throw;
// 		}
// 	}
// 	else
// 	{
// 		// Copy assign same type
// 		a_CopyFrom.Visit(sCopyAssigner{m_Payload});
// 	}
// 	return *this;
// }





// cTag & cTag::operator = (cTag && a_MoveFrom)
// {
// 	if (m_TagId != a_MoveFrom.m_TagId)
// 	{
// 		// Move assign different type
// 		Destroy();
// 		m_TagId = a_MoveFrom.m_TagId;

// 		try
// 		{
// 			a_MoveFrom.Visit(sMoveConstructor{m_Payload});
// 		}
// 		catch (...)
// 		{
// 			// We just deleted the old value but the new value failed to construct
// 			// Tag as empty to avoid double deletion
// 			m_TagId = TAG_End;
// 			m_Payload.Construct(cEmptyTag{});
// 			throw;
// 		}
// 	}
// 	else
// 	{
// 		// Move assign same type
// 		a_MoveFrom.Visit(sMoveAssigner{m_Payload});
// 	}
// 	return *this;
// }

}  // namespace TreeNBT
