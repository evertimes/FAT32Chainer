#pragma once
#include <string>
//Функция копирования каталожной структуры
void copyDirs(std::wstring path, std::wstring destPath,int* returnCode) {
	using namespace System;
	CreateDirectory(destPath.c_str(), NULL);
	for (const auto& entry : std::filesystem::recursive_directory_iterator(path)) {
		std::filesystem::path curpath = entry.path();
		std::wstring sf = curpath.wstring();
		String^ path3 = gcnew String(curpath.c_str());
		String^ pathToRemove = gcnew String(path.c_str());
		path3 = path3->Replace(pathToRemove, "");
		String^ firstPath = gcnew String(destPath.c_str()) + path3;
		std::wstring dp = msclr::interop::marshal_as<std::wstring>(firstPath);
		if (CopyFile(sf.c_str(), dp.c_str(), 0)) {
			//Если копирование выполнено успешно, то не принимаем никаких действий
		}
		else {
			//Иначе создаем директорию
			CreateDirectory(dp.c_str(), NULL);
		}
	}
}
//Получение цепочки номеров кластеров
long* getClusterChain(long firstCluster,std::vector<long>* chain,std::wstring disk) {
	chain->push_back(firstCluster);
	long currentCluster = firstCluster;
	std::wstring prefix = L"\\\\.\\";
	disk = prefix.append(disk);
	int i = 0;
	DWORD dwRead;
	HANDLE hDisk = CreateFile(disk.c_str(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, 0, OPEN_EXISTING, FILE_ATTRIBUTE_READONLY, 0);
	if (hDisk == INVALID_HANDLE_VALUE) // this may happen if another program is already reading from disk
	{
		CloseHandle(hDisk);
		return NULL;
	}
	//Получение начала FAt таблицы
	byte* buffer = (byte*)malloc(512);
	ReadFile(hDisk, buffer, 512, &dwRead, 0);  // read sector
	byte* numreserv = (byte*)malloc(2);
	for (int i = 0; i < 2; i++) {
		numreserv[i] = buffer[0x0E + i];
	}
	uint16_t nreserv;
	free(buffer);
	std::memcpy(&nreserv, numreserv, sizeof(uint16_t));
	while (currentCluster != 0x0FFFFFFF) {
		i++;
		//Получение смещения и номера сектора
		long fatTableSector = (currentCluster * 4) / 512;
		long fatTableOffset = (currentCluster * 4) % 512;
		SetFilePointer(hDisk, nreserv * 512 + fatTableSector * 512, 0, FILE_BEGIN); // Выбор сектора
		long long clusterNum = 0;
		unsigned char numclust[4];
		byte* buf = (byte*)malloc(512);
		ReadFile(hDisk, buf, 512, &dwRead, 0);  // Чтение сектора
		memcpy(numclust, buf + fatTableOffset, 4);
		memcpy(&clusterNum, numclust, 4);
		chain->push_back(clusterNum);
		currentCluster = clusterNum;
		free(buf);
	}
}