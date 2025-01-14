// **********************************************************************
// This file was generated by a TARS parser!
// TARS version 3.0.13.
// **********************************************************************

#ifndef __DEMOSERVANT_H_
#define __DEMOSERVANT_H_

#include <map>
#include <string>
#include <vector>
#include "tup/Tars.h"
#include "tup/TarsJson.h"
using namespace std;
#include "servant/ServantProxy.h"
#include "servant/Servant.h"
#include "promise/promise.h"
#include "servant/Application.h"


namespace DemoApp
{

    /* callback of async proxy for client */
    class DemoServantPrxCallback: public tars::ServantProxyCallback
    {
    public:
        virtual ~DemoServantPrxCallback(){}
        virtual void callback_test(tars::Int32 ret)
        { throw std::runtime_error("callback_test() override incorrect."); }
        virtual void callback_test_exception(tars::Int32 ret)
        { throw std::runtime_error("callback_test_exception() override incorrect."); }

    public:
        virtual const map<std::string, std::string> & getResponseContext() const
        {
            CallbackThreadData * pCbtd = CallbackThreadData::getData();
            assert(pCbtd != NULL);

            if(!pCbtd->getContextValid())
            {
                throw TC_Exception("cann't get response context");
            }
            return pCbtd->getResponseContext();
        }

    public:
        virtual int onDispatch(tars::ReqMessagePtr _msg_)
        {
            static ::std::string __DemoServant_all[]=
            {
                "test"
            };
            auto it = _msg_->response->status.find("TARS_FUNC");
            pair<string*, string*> r = equal_range(__DemoServant_all, __DemoServant_all+1, (it==_msg_->response->status.end())?_msg_->request.sFuncName:it->second);
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __DemoServant_all)
            {
                case 0:
                {
                    if (_msg_->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_test_exception(_msg_->response->iRet);

                        return _msg_->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(_msg_->response->sBuffer);
                    tars::Int32 _ret;
                    _is.read(_ret, 0, true);

                    ServantProxyThreadData *_pSptd_ = ServantProxyThreadData::getData();
                    if (_pSptd_ && _pSptd_->_traceCall)
                    {
                        string _trace_param_;
                        int _trace_param_flag_ = _pSptd_->needTraceParam(ServantProxyThreadData::TraceContext::EST_CR, _is.size());
                        if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                        {
                            tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                            _p_->value[""] = tars::JsonOutput::writeJson(_ret);
                            _trace_param_ = tars::TC_Json::writeValue(_p_);
                        }
                        else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                        {
                            _trace_param_ = "{\"trace_param_over_max_len\":true}";
                        }
                        TARS_TRACE(_pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_CR), TRACE_ANNOTATION_CR, "", ServerConfig::Application + "." + ServerConfig::ServerName, "test", 0, _trace_param_, "");
                    }

                    CallbackThreadData * pCbtd = CallbackThreadData::getData();
                    assert(pCbtd != NULL);

                    pCbtd->setResponseContext(_msg_->response->context);

                    callback_test(_ret);

                    pCbtd->delResponseContext();

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<DemoServantPrxCallback> DemoServantPrxCallbackPtr;

    //callback of promise async proxy for client
    class DemoServantPrxCallbackPromise: public tars::ServantProxyCallback
    {
    public:
        virtual ~DemoServantPrxCallbackPromise(){}
    public:
        struct Promisetest: virtual public TC_HandleBase
        {
        public:
            tars::Int32 _ret;
            map<std::string, std::string> _mRspContext;
        };
        
        typedef tars::TC_AutoPtr< DemoServantPrxCallbackPromise::Promisetest > PromisetestPtr;

        DemoServantPrxCallbackPromise(const tars::Promise< DemoServantPrxCallbackPromise::PromisetestPtr > &promise)
        : _promise_test(promise)
        {}
        
        virtual void callback_test(const DemoServantPrxCallbackPromise::PromisetestPtr &ptr)
        {
            _promise_test.setValue(ptr);
        }
        virtual void callback_test_exception(tars::Int32 ret)
        {
            std::string str("");
            str += "Function:test_exception|Ret:";
            str += TC_Common::tostr(ret);
            _promise_test.setException(tars::copyException(str, ret));
        }

    protected:
        tars::Promise< DemoServantPrxCallbackPromise::PromisetestPtr > _promise_test;

    public:
        virtual int onDispatch(tars::ReqMessagePtr _msg_)
        {
            static ::std::string __DemoServant_all[]=
            {
                "test"
            };

            pair<string*, string*> r = equal_range(__DemoServant_all, __DemoServant_all+1, string(_msg_->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __DemoServant_all)
            {
                case 0:
                {
                    if (_msg_->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_test_exception(_msg_->response->iRet);

                        return _msg_->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(_msg_->response->sBuffer);

                    DemoServantPrxCallbackPromise::PromisetestPtr ptr = new DemoServantPrxCallbackPromise::Promisetest();

                    try
                    {
                        _is.read(ptr->_ret, 0, true);

                    }
                    catch(std::exception &ex)
                    {
                        callback_test_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_test_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    ptr->_mRspContext = _msg_->response->context;

                    callback_test(ptr);

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<DemoServantPrxCallbackPromise> DemoServantPrxCallbackPromisePtr;

    /* callback of coroutine async proxy for client */
    class DemoServantCoroPrxCallback: public DemoServantPrxCallback
    {
    public:
        virtual ~DemoServantCoroPrxCallback(){}
    public:
        virtual const map<std::string, std::string> & getResponseContext() const { return _mRspContext; }

        virtual void setResponseContext(const map<std::string, std::string> &mContext) { _mRspContext = mContext; }

    public:
        int onDispatch(tars::ReqMessagePtr _msg_)
        {
            static ::std::string __DemoServant_all[]=
            {
                "test"
            };

            pair<string*, string*> r = equal_range(__DemoServant_all, __DemoServant_all+1, string(_msg_->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __DemoServant_all)
            {
                case 0:
                {
                    if (_msg_->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_test_exception(_msg_->response->iRet);

                        return _msg_->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(_msg_->response->sBuffer);
                    try
                    {
                        tars::Int32 _ret;
                        _is.read(_ret, 0, true);

                        setResponseContext(_msg_->response->context);

                        callback_test(_ret);

                    }
                    catch(std::exception &ex)
                    {
                        callback_test_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_test_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    protected:
        map<std::string, std::string> _mRspContext;
    };
    typedef tars::TC_AutoPtr<DemoServantCoroPrxCallback> DemoServantCoroPrxCallbackPtr;

    /* proxy for client */
    class DemoServantProxy : public tars::ServantProxy
    {
    public:
        typedef map<string, string> TARS_CONTEXT;
        tars::Int32 test(const map<string, string> &context = TARS_CONTEXT(),map<string, string> * pResponseContext = NULL)
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            ServantProxyThreadData *_pSptd_ = ServantProxyThreadData::getData();
            if (_pSptd_ && _pSptd_->_traceCall)
            {
                _pSptd_->newSpan();
                string _trace_param_;
                int _trace_param_flag_ = _pSptd_->needTraceParam(ServantProxyThreadData::TraceContext::EST_CS, _os.getLength());
                if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                {
                    tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                    _trace_param_ = tars::TC_Json::writeValue(_p_);
                }
                else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                {
                    _trace_param_ = "{\"trace_param_over_max_len\":true}";
                }
                TARS_TRACE(_pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_CS), TRACE_ANNOTATION_CS, ServerConfig::Application + "." + ServerConfig::ServerName, tars_name(), "test", 0, _trace_param_, "");
            }

            std::map<string, string> _mStatus;
            shared_ptr<tars::ResponsePacket> rep = tars_invoke(tars::TARSNORMAL,"test", _os, context, _mStatus);
            if(pResponseContext)
            {
                pResponseContext->swap(rep->context);
            }

            tars::TarsInputStream<tars::BufferReader> _is;
            _is.setBuffer(rep->sBuffer);
            tars::Int32 _ret;
            _is.read(_ret, 0, true);
            if (_pSptd_ && _pSptd_->_traceCall)
            {
                string _trace_param_;
                int _trace_param_flag_ = _pSptd_->needTraceParam(ServantProxyThreadData::TraceContext::EST_CR, _is.size());
                if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                {
                    tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                    _p_->value[""] = tars::JsonOutput::writeJson(_ret);
                    _trace_param_ = tars::TC_Json::writeValue(_p_);
                }
                else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                {
                    _trace_param_ = "{\"trace_param_over_max_len\":true}";
                }
                TARS_TRACE(_pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_CR), TRACE_ANNOTATION_CR, ServerConfig::Application + "." + ServerConfig::ServerName, tars_name(), "test", 0, _trace_param_, "");
            }

            return _ret;
        }

        void async_test(DemoServantPrxCallbackPtr callback,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            std::map<string, string> _mStatus;
            ServantProxyThreadData *_pSptd_ = ServantProxyThreadData::getData();
            if (_pSptd_ && _pSptd_->_traceCall)
            {
                _pSptd_->newSpan();
                string _trace_param_;
                int _trace_param_flag_ = _pSptd_->needTraceParam(ServantProxyThreadData::TraceContext::EST_CS, _os.getLength());
                if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                {
                    tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                    _trace_param_ = tars::TC_Json::writeValue(_p_);
                }
                else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                {
                    _trace_param_ = "{\"trace_param_over_max_len\":true}";
                }
                TARS_TRACE(_pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_CS), TRACE_ANNOTATION_CS, ServerConfig::Application + "." + ServerConfig::ServerName, tars_name(), "test", 0, _trace_param_, "");
            }
            tars_invoke_async(tars::TARSNORMAL,"test", _os, context, _mStatus, callback);
        }
        
        tars::Future< DemoServantPrxCallbackPromise::PromisetestPtr > promise_async_test(const map<string, string>& context)
        {
            tars::Promise< DemoServantPrxCallbackPromise::PromisetestPtr > promise;
            DemoServantPrxCallbackPromisePtr callback = new DemoServantPrxCallbackPromise(promise);

            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"test", _os, context, _mStatus, callback);

            return promise.getFuture();
        }

        void coro_test(DemoServantCoroPrxCallbackPtr callback,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"test", _os, context, _mStatus, callback, true);
        }

        DemoServantProxy* tars_hash(uint32_t key)
        {
            return (DemoServantProxy*)ServantProxy::tars_hash(key);
        }

        DemoServantProxy* tars_consistent_hash(uint32_t key)
        {
            return (DemoServantProxy*)ServantProxy::tars_consistent_hash(key);
        }

        DemoServantProxy* tars_open_trace(bool traceParam = false)
        {
            return (DemoServantProxy*)ServantProxy::tars_open_trace(traceParam);
        }

        DemoServantProxy* tars_set_timeout(int msecond)
        {
            return (DemoServantProxy*)ServantProxy::tars_set_timeout(msecond);
        }

        static const char* tars_prxname() { return "DemoServantProxy"; }
    };
    typedef tars::TC_AutoPtr<DemoServantProxy> DemoServantPrx;

    /* servant for server */
    class DemoServant : public tars::Servant
    {
    public:
        virtual ~DemoServant(){}
        virtual tars::Int32 test(tars::TarsCurrentPtr _current_) = 0;
        static void async_response_test(tars::TarsCurrentPtr _current_, tars::Int32 _ret)
        {
            size_t _rsp_len_ = 0;
            if (_current_->getRequestVersion() == TUPVERSION )
            {
                UniAttribute<tars::BufferWriterVector, tars::BufferReader>  _tarsAttr_;
                _tarsAttr_.setVersion(_current_->getRequestVersion());
                _tarsAttr_.put("", _ret);
                _tarsAttr_.put("tars_ret", _ret);

                vector<char> sTupResponseBuffer;
                _tarsAttr_.encode(sTupResponseBuffer);
                _current_->sendResponse(tars::TARSSERVERSUCCESS, sTupResponseBuffer);
                _rsp_len_ = sTupResponseBuffer.size();
            }
            else if (_current_->getRequestVersion() == JSONVERSION)
            {
                tars::JsonValueObjPtr _p = new tars::JsonValueObj();
                _p->value["tars_ret"] = tars::JsonOutput::writeJson(_ret);
                vector<char> sJsonResponseBuffer;
                tars::TC_Json::writeValue(_p, sJsonResponseBuffer);
                _current_->sendResponse(tars::TARSSERVERSUCCESS, sJsonResponseBuffer);
                _rsp_len_ = sJsonResponseBuffer.size();
            }
            else
            {
                tars::TarsOutputStream<tars::BufferWriterVector> _os;
                _os.write(_ret, 0);

                _rsp_len_ = _os.getLength();
                _current_->sendResponse(tars::TARSSERVERSUCCESS, _os);
            }
            if (_current_->isTraced())
            {
                string _trace_param_;
                int _trace_param_flag_ = ServantProxyThreadData::needTraceParam(ServantProxyThreadData::TraceContext::EST_SS, _current_->getTraceKey(), _rsp_len_);
                if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                {
                    tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                    _p_->value[""] = tars::JsonOutput::writeJson(_ret);
                    _trace_param_ = tars::TC_Json::writeValue(_p_);
                }
                else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                {
                    _trace_param_ = "{\"trace_param_over_max_len\":true}";
                }
                TARS_TRACE(_current_->getTraceKey(), TRACE_ANNOTATION_SS, "", ServerConfig::Application + "." + ServerConfig::ServerName, "test", 0, _trace_param_, "");
            }

        }
        static void async_response_push_test(tars::CurrentPtr _current_, tars::Int32 _ret, const map<string, string> &_context = tars::Current::TARS_STATUS())
        {
            {
                tars::TarsOutputStream<tars::BufferWriterVector> _os;
                _os.write(_ret, 0);

                _current_->sendPushResponse( tars::TARSSERVERSUCCESS ,"test", _os, _context);
            }
        }

    public:
        int onDispatch(tars::TarsCurrentPtr _current, vector<char> &_sResponseBuffer)
        {
            static ::std::string __DemoApp__DemoServant_all[]=
            {
                "test"
            };

            pair<string*, string*> r = equal_range(__DemoApp__DemoServant_all, __DemoApp__DemoServant_all+1, _current->getFuncName());
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __DemoApp__DemoServant_all)
            {
                case 0:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;
                    _is.setBuffer(_current->getRequestBuffer());
                    if (_current->getRequestVersion() == TUPVERSION)
                    {
                        UniAttribute<tars::BufferWriterVector, tars::BufferReader>  _tarsAttr_;
                        _tarsAttr_.setVersion(_current->getRequestVersion());
                        _tarsAttr_.decode(_current->getRequestBuffer());
                    }
                    else if (_current->getRequestVersion() == JSONVERSION)
                    {
                        tars::JsonValueObjPtr _jsonPtr = tars::JsonValueObjPtr::dynamicCast(tars::TC_Json::getValue(_current->getRequestBuffer()));
                    }
                    else
                    {
                    }
                    ServantProxyThreadData *_pSptd_ = ServantProxyThreadData::getData();
                    if (_pSptd_ && _pSptd_->_traceCall)
                    {
                        string _trace_param_;
                        int _trace_param_flag_ = _pSptd_->needTraceParam(ServantProxyThreadData::TraceContext::EST_SR, _is.size());
                        if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                        {
                            tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                            _trace_param_ = tars::TC_Json::writeValue(_p_);
                        }
                        else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                        {
                            _trace_param_ = "{\"trace_param_over_max_len\":true}";
                        }
                        TARS_TRACE(_pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_SR), TRACE_ANNOTATION_SR, "", ServerConfig::Application + "." + ServerConfig::ServerName, "test", 0, _trace_param_, "");
                    }

                    tars::Int32 _ret = test(_current);
                    if(_current->isResponse())
                    {
                        if (_current->getRequestVersion() == TUPVERSION)
                        {
                            UniAttribute<tars::BufferWriterVector, tars::BufferReader>  _tarsAttr_;
                            _tarsAttr_.setVersion(_current->getRequestVersion());
                            _tarsAttr_.put("", _ret);
                            _tarsAttr_.put("tars_ret", _ret);
                            _tarsAttr_.encode(_sResponseBuffer);
                        }
                        else if (_current->getRequestVersion() == JSONVERSION)
                        {
                            tars::JsonValueObjPtr _p = new tars::JsonValueObj();
                            _p->value["tars_ret"] = tars::JsonOutput::writeJson(_ret);
                            tars::TC_Json::writeValue(_p, _sResponseBuffer);
                        }
                        else
                        {
                            tars::TarsOutputStream<tars::BufferWriterVector> _os;
                            _os.write(_ret, 0);
                            _os.swap(_sResponseBuffer);
                        }
                        if (_pSptd_ && _pSptd_->_traceCall)
                        {
                            string _trace_param_;
                            int _trace_param_flag_ = _pSptd_->needTraceParam(ServantProxyThreadData::TraceContext::EST_SS, _sResponseBuffer.size());
                            if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                            {
                                tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                                _p_->value[""] = tars::JsonOutput::writeJson(_ret);
                                _trace_param_ = tars::TC_Json::writeValue(_p_);
                            }
                            else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                            {
                                _trace_param_ = "{\"trace_param_over_max_len\":true}";
                            }
                            TARS_TRACE(_pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_SS), TRACE_ANNOTATION_SS, "", ServerConfig::Application + "." + ServerConfig::ServerName, "test", 0, _trace_param_, "");
                        }

                    }
                    else if(_pSptd_ && _pSptd_->_traceCall)
                    {
                        _current->setTrace(_pSptd_->_traceCall, _pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_SS));
                    }

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }
    };


}



#endif
