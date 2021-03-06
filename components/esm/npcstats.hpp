#ifndef OPENMW_ESM_NPCSTATS_H
#define OPENMW_ESM_NPCSTATS_H

#include <string>
#include <vector>
#include <map>

#include "statstate.hpp"

namespace ESM
{
    class ESMReader;
    class ESMWriter;

    // format 0, saved games only

    struct NpcStats
    {
        struct Skill
        {
            StatState<int> mRegular;
            StatState<int> mWerewolf;
        };

        struct Faction
        {
            bool mExpelled;
            int mRank;
            int mReputation;

            Faction();
        };

        StatState<int> mWerewolfAttributes[8];
        bool mIsWerewolf;

        std::map<std::string, Faction> mFactions; // lower case IDs
        int mDisposition;
        Skill mSkills[27];
        int mBounty;
        int mReputation;
        int mWerewolfKills;
        int mProfit;
        int mLevelProgress;
        int mSkillIncrease[8];
        std::vector<std::string> mUsedIds; // lower case IDs
        float mTimeToStartDrowning;
        int mCrimeId;

        /// Initialize to default state
        void blank();

        void load (ESMReader &esm);
        void save (ESMWriter &esm) const;
    };
}

#endif
