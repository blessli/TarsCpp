// **********************************************************************
// This file was generated by a TARS parser!
// TARS version 3.0.13.
// **********************************************************************

#ifndef __ENDPOINTF_H_
#define __ENDPOINTF_H_

#include <map>
#include <string>
#include <vector>
#include "tup/Tars.h"
#include "tup/TarsJson.h"
using namespace std;


namespace tars
{
    struct EndpointF : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "tars.EndpointF";
        }
        static string MD5()
        {
            return "150be7f7cdd22b6d644d53a697d24103";
        }
        EndpointF()
        {
            resetDefautlt();
        }
        void resetDefautlt()
        {
            host = "";
            port = 0;
            timeout = 0;
            istcp = 0;
            grid = 0;
            groupworkid = 0;
            grouprealid = 0;
            setId = "";
            qos = 0;
            bakFlag = 0;
            weight = 0;
            weightType = 0;
            authType = 0;
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(host, 0);
            _os.write(port, 1);
            _os.write(timeout, 2);
            _os.write(istcp, 3);
            _os.write(grid, 4);
            if (groupworkid != 0)
            {
                _os.write(groupworkid, 5);
            }
            if (grouprealid != 0)
            {
                _os.write(grouprealid, 6);
            }
            if (setId != "")
            {
                _os.write(setId, 7);
            }
            if (qos != 0)
            {
                _os.write(qos, 8);
            }
            if (bakFlag != 0)
            {
                _os.write(bakFlag, 9);
            }
            if (weight != 0)
            {
                _os.write(weight, 11);
            }
            if (weightType != 0)
            {
                _os.write(weightType, 12);
            }
            if (authType != 0)
            {
                _os.write(authType, 13);
            }
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(host, 0, true);
            _is.read(port, 1, true);
            _is.read(timeout, 2, true);
            _is.read(istcp, 3, true);
            _is.read(grid, 4, true);
            _is.read(groupworkid, 5, false);
            _is.read(grouprealid, 6, false);
            _is.read(setId, 7, false);
            _is.read(qos, 8, false);
            _is.read(bakFlag, 9, false);
            _is.read(weight, 11, false);
            _is.read(weightType, 12, false);
            _is.read(authType, 13, false);
        }
        tars::JsonValueObjPtr writeToJson() const
        {
            tars::JsonValueObjPtr p = new tars::JsonValueObj();
            p->value["host"] = tars::JsonOutput::writeJson(host);
            p->value["port"] = tars::JsonOutput::writeJson(port);
            p->value["timeout"] = tars::JsonOutput::writeJson(timeout);
            p->value["istcp"] = tars::JsonOutput::writeJson(istcp);
            p->value["grid"] = tars::JsonOutput::writeJson(grid);
            p->value["groupworkid"] = tars::JsonOutput::writeJson(groupworkid);
            p->value["grouprealid"] = tars::JsonOutput::writeJson(grouprealid);
            p->value["setId"] = tars::JsonOutput::writeJson(setId);
            p->value["qos"] = tars::JsonOutput::writeJson(qos);
            p->value["bakFlag"] = tars::JsonOutput::writeJson(bakFlag);
            p->value["weight"] = tars::JsonOutput::writeJson(weight);
            p->value["weightType"] = tars::JsonOutput::writeJson(weightType);
            p->value["authType"] = tars::JsonOutput::writeJson(authType);
            return p;
        }
        string writeToJsonString() const
        {
            return tars::TC_Json::writeValue(writeToJson());
        }
        void readFromJson(const tars::JsonValuePtr & p, bool isRequire = true)
        {
            resetDefautlt();
            if(NULL == p.get() || p->getType() != tars::eJsonTypeObj)
            {
                char s[128];
                snprintf(s, sizeof(s), "read 'struct' type mismatch, get type: %d.", (p.get() ? p->getType() : 0));
                throw tars::TC_Json_Exception(s);
            }
            tars::JsonValueObjPtr pObj=tars::JsonValueObjPtr::dynamicCast(p);
            tars::JsonInput::readJson(host,pObj->value["host"], true);
            tars::JsonInput::readJson(port,pObj->value["port"], true);
            tars::JsonInput::readJson(timeout,pObj->value["timeout"], true);
            tars::JsonInput::readJson(istcp,pObj->value["istcp"], true);
            tars::JsonInput::readJson(grid,pObj->value["grid"], true);
            tars::JsonInput::readJson(groupworkid,pObj->value["groupworkid"], false);
            tars::JsonInput::readJson(grouprealid,pObj->value["grouprealid"], false);
            tars::JsonInput::readJson(setId,pObj->value["setId"], false);
            tars::JsonInput::readJson(qos,pObj->value["qos"], false);
            tars::JsonInput::readJson(bakFlag,pObj->value["bakFlag"], false);
            tars::JsonInput::readJson(weight,pObj->value["weight"], false);
            tars::JsonInput::readJson(weightType,pObj->value["weightType"], false);
            tars::JsonInput::readJson(authType,pObj->value["authType"], false);
        }
        void readFromJsonString(const string & str)
        {
            readFromJson(tars::TC_Json::getValue(str));
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(host,"host");
            _ds.display(port,"port");
            _ds.display(timeout,"timeout");
            _ds.display(istcp,"istcp");
            _ds.display(grid,"grid");
            _ds.display(groupworkid,"groupworkid");
            _ds.display(grouprealid,"grouprealid");
            _ds.display(setId,"setId");
            _ds.display(qos,"qos");
            _ds.display(bakFlag,"bakFlag");
            _ds.display(weight,"weight");
            _ds.display(weightType,"weightType");
            _ds.display(authType,"authType");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(host, true);
            _ds.displaySimple(port, true);
            _ds.displaySimple(timeout, true);
            _ds.displaySimple(istcp, true);
            _ds.displaySimple(grid, true);
            _ds.displaySimple(groupworkid, true);
            _ds.displaySimple(grouprealid, true);
            _ds.displaySimple(setId, true);
            _ds.displaySimple(qos, true);
            _ds.displaySimple(bakFlag, true);
            _ds.displaySimple(weight, true);
            _ds.displaySimple(weightType, true);
            _ds.displaySimple(authType, false);
            return _os;
        }
    public:
        std::string host;
        tars::Int32 port;
        tars::Int32 timeout;
        tars::Int32 istcp;
        tars::Int32 grid;
        tars::Int32 groupworkid;
        tars::Int32 grouprealid;
        std::string setId;
        tars::Int32 qos;
        tars::Int32 bakFlag;
        tars::Int32 weight;
        tars::Int32 weightType;
        tars::Int32 authType;
    };
    inline bool operator==(const EndpointF&l, const EndpointF&r)
    {
        return l.host == r.host && l.port == r.port && l.timeout == r.timeout && l.istcp == r.istcp && l.grid == r.grid && l.groupworkid == r.groupworkid && l.grouprealid == r.grouprealid && l.setId == r.setId && l.qos == r.qos && l.bakFlag == r.bakFlag && l.weight == r.weight && l.weightType == r.weightType && l.authType == r.authType;
    }
    inline bool operator!=(const EndpointF&l, const EndpointF&r)
    {
        return !(l == r);
    }
    inline ostream& operator<<(ostream & os,const EndpointF&r)
    {
        os << r.writeToJsonString();
        return os;
    }
    inline istream& operator>>(istream& is,EndpointF&l)
    {
        std::istreambuf_iterator<char> eos;
        std::string s(std::istreambuf_iterator<char>(is), eos);
        l.readFromJsonString(s);
        return is;
    }
    inline bool operator<(const EndpointF&l, const EndpointF&r)
    {
        if(l.host != r.host)  return (l.host < r.host);
        if(l.port != r.port)  return (l.port < r.port);
        if(l.timeout != r.timeout)  return (l.timeout < r.timeout);
        if(l.istcp != r.istcp)  return (l.istcp < r.istcp);
        if(l.grid != r.grid)  return (l.grid < r.grid);
        if(l.qos != r.qos)  return (l.qos < r.qos);
        if(l.weight != r.weight)  return (l.weight < r.weight);
        if(l.weightType != r.weightType)  return (l.weightType < r.weightType);
        if(l.authType != r.authType)  return (l.authType < r.authType);
        return false;
    }
    inline bool operator<=(const EndpointF&l, const EndpointF&r)
    {
        return !(r < l);
    }
    inline bool operator>(const EndpointF&l, const EndpointF&r)
    {
        return r < l;
    }
    inline bool operator>=(const EndpointF&l, const EndpointF&r)
    {
        return !(l < r);
    }


}



#endif
