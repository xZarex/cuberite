
#include "Globals.h"
#include "WorldStorage/TreeNBT.h"

using namespace TreeNBT;

namespace
{

void TestListTags() {
	cTag listTag;
	listTag.assign(cList());

	auto int8Tag = std::make_shared<cTag>();
	int8Tag->assign(static_cast<Int8>(1));

	auto int9Tag = std::make_shared<cTag>();
	int9Tag->assign(static_cast<Int8>(2));

	ASSERT(std::get<cList>(listTag).TryPushBack(int8Tag));
	ASSERT(std::get<cList>(listTag).TryPushBack(int9Tag));
}

}  // namespace (anonymous)




int main(int argc, char ** argv)
{
	FLOG("TreeNBT tests started");

	TestListTags();

	FLOG("TreeNBT tests finished");
}




