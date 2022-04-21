#pragma once
#include <vector>

class OAMEntry;
class OAMTable final
{
public:
	OAMTable();
	~OAMTable();

	bool AddEntry(const OAMEntry& entry);
	OAMEntry& GetEntry(int idx);
	OAMEntry RemoveEntry(int idx);

private:
	const int m_MaxEntries;
	std::vector<OAMEntry> m_Entries;
};

