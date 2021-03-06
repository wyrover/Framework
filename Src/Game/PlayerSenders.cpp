#include "Player.hpp"
#include <Game/GOMDatabase.hpp>
#include <System/Log.h>

namespace Game
{
	void Player::SendReplicationTransaction(GOMDatabase* gomDatabase)
	{
		GOMVisitor visitor;
		gomDatabase->VisitAll(Game::GOMDatabase::kAllGOMServers, visitor);

		// Don't send if we have nothing to send...
		if(visitor.gomEntries.empty())
		{
			synchronized = true;
			return;
		}

		GOMTransaction transaction;

		if(visitor.gomEntries.size())
		{
			transaction.SetUpdateMap(visitor.gomEntries);
		}

		Write(transaction.ToPacket(Player::kReplicationTransaction));

		synchronized = true;
	}

	void Player::SendAwareness()
	{
		Framework::Network::Packet packet(kAwareness);
		Write(packet);
	}
}