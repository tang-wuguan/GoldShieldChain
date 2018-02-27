// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x8d;
        pchMessageStart[1] = 0x4c;
        pchMessageStart[2] = 0x71;
        pchMessageStart[3] = 0x63;
        vAlertPubKey = ParseHex("04f48d971f5e2b9c4deb74a7b4ff1b732d6162fe34157a25ba676d6e024838a288b4b290dc1bab1a9d2edaedad544ed2b92713d215e2268921864017cf63ea0239");
        nDefaultPort = 17113;
        nRPCPort = 17114;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        //
        //CBlock(hash=000001faef25dec4fbcf906e6242621df2c183bf232f263d0ba5b101911e4563, ver=1, hashPrevBlock=0000000000000000000000000000000000000000000000000000000000000000, hashMerkleRoot=12630d16a97f24b287c8c2594dda5fb98c9e6c70fc61d44191931ea2aa08dc90, nTime=1393221600, nBits=1e0fffff, nNonce=164482, vtx=1, vchBlockSig=)
        //  Coinbase(hash=12630d16a9, nTime=1393221600, ver=1, vin.size=1, vout.size=1, nLockTime=0)
        //    CTxIn(COutPoint(0000000000, 4294967295), coinbase 00012a24323020466562203230313420426974636f696e2041544d7320636f6d6520746f20555341)
        //    CTxOut(empty)
        //  vMerkleTree: 12630d16a9
        const char* pszTimestamp = "GoldShieldChain - Healthy e-store digital assets";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        CTransaction txNew(1, 1515748188, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1515748188;
        genesis.nBits = 520159231;
        genesis.nNonce = 779;  
        hashGenesisBlock = genesis.GetHash();
         assert(hashGenesisBlock == uint256("0x000091a56b5d308a2710675e9cffe15ed362172738b92e4577cea40ba1aba3fd"));
         assert(genesis.hashMerkleRoot == uint256("0x8bdd51ba39cb39c17184a774dc4f671376764b7420071fd052441e9c9bfdc8e5"));
        vSeeds.push_back(CDNSSeedData("39.106.156.109", "39.106.156.109"));
        vSeeds.push_back(CDNSSeedData("39.106.154.204", "39.106.154.204"));
        vSeeds.push_back(CDNSSeedData("39.106.156.2", "39.106.156.2"));
	vSeeds.push_back(CDNSSeedData("39.106.154.98", "39.106.154.98"));
	vSeeds.push_back(CDNSSeedData("39.106.155.20", "39.106.155.20"));
	vSeeds.push_back(CDNSSeedData("39.106.154.138", "39.106.154.138"));
	vSeeds.push_back(CDNSSeedData("39.106.155.158", "39.106.155.158"));
	vSeeds.push_back(CDNSSeedData("39.106.154.27", "39.106.154.27"));
	vSeeds.push_back(CDNSSeedData("39.106.154.88", "39.106.154.88"));
	vSeeds.push_back(CDNSSeedData("39.106.156.159", "39.106.156.159"));
	vSeeds.push_back(CDNSSeedData("118.190.3.64", "118.190.3.64"));
	vSeeds.push_back(CDNSSeedData("106.15.95.66", "106.15.95.66"));
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 75);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 85);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1, 153);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nLastPOWBlock = 500;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x2a;
        pchMessageStart[1] = 0x2b;
        pchMessageStart[2] = 0x36;
        pchMessageStart[3] = 0x42;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("");
        nDefaultPort = 21134;
        nRPCPort = 21135;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 89122;
        hashGenesisBlock = genesis.GetHash();
        /*assert(hashGenesisBlock == uint256("0x00003e0095045e13231b44e4d5624aac6c708a23833fb653c614385cb4cb6a48"));*/ 
        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 196);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 239);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nLastPOWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xca;
        pchMessageStart[1] = 0xaf;
        pchMessageStart[2] = 0xc5;
        pchMessageStart[3] = 0xf8;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1514275684;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 0;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 31135;
        strDataDir = "regtest";

/*        assert(hashGenesisBlock == uint256("0x2aa199c0ed05ffd96ddbd28e5e4d475a4823774b0cb711c14c647c4f475d6592"));
*/
        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
