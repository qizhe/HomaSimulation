//
// Generated file, do not edit! Created by nedtool 4.6 from HomaPkt.msg.
//

#ifndef _HOMAPKT_M_H_
#define _HOMAPKT_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include <vector>
#include "inet/networklayer/common/L3Address.h"
typedef std::vector<uint32_t> UnsignedVec;
// }}

/**
 * Enum generated from <tt>HomaPkt.msg:25</tt> by nedtool.
 * <pre>
 * enum PktType
 * {
 * 
 *     REQUEST = 0;
 *     GRANT = 1;
 *     SCHED_DATA = 2;
 *     UNSCHED_DATA = 3;
 *     HOMA_ACK = 4;
 * }
 * </pre>
 */
enum PktType {
    REQUEST = 0,
    GRANT = 1,
    SCHED_DATA = 2,
    UNSCHED_DATA = 3,
    HOMA_ACK = 4
};

/**
 * Struct generated from HomaPkt.msg:34 by nedtool.
 */
struct UnschedFields
{
    UnschedFields();
    uint32_t msgByteLen;
    simtime_t msgCreationTime;
    uint32_t totalUnschedBytes;
    uint32_t firstByte;
    uint32_t lastByte;
    UnsignedVec prioUnschedBytes;
};

void doPacking(cCommBuffer *b, UnschedFields& a);
void doUnpacking(cCommBuffer *b, UnschedFields& a);

/**
 * Struct generated from HomaPkt.msg:56 by nedtool.
 */
struct GrantFields
{
    GrantFields();
    uint16_t grantBytes;
    uint32_t offset;
    uint16_t schedPrio;
    UnsignedVec sizeReqBytesPrio;
    UnsignedVec sizeUnschedBytesPrio;
    uint32_t remainingSize;
};

void doPacking(cCommBuffer *b, GrantFields& a);
void doUnpacking(cCommBuffer *b, GrantFields& a);

/**
 * Struct generated from HomaPkt.msg:70 by nedtool.
 */
struct SchedDataFields
{
    SchedDataFields();
    uint32_t firstByte;
    uint32_t lastByte;
};

void doPacking(cCommBuffer *b, SchedDataFields& a);
void doUnpacking(cCommBuffer *b, SchedDataFields& a);

/**
 * Class generated from <tt>HomaPkt.msg:80</tt> by nedtool.
 * <pre>
 * //
 * // generated message class
 * //
 * packet HomaPkt
 * {
 *     @customize(true);
 * 
 *     inet::L3Address srcAddr;
 *     inet::L3Address destAddr;
 *     uint64_t msgId;
 *     uint32_t priority = 1;
 *     int pktType @enum(PktType);
 * 
 *     // depending on the pktType, only one of the three following struct are
 *     // relevant in the context of a HomaPkt.
 *     UnschedFields unschedFields;    // Used for both request and unsched
 *     GrantFields grantFields;            // Used only for grants
 *     SchedDataFields schedDataFields;    // Used only for scheduled data
 * }
 * </pre>
 *
 * HomaPkt_Base is only useful if it gets subclassed, and HomaPkt is derived from it.
 * The minimum code to be written for HomaPkt is the following:
 *
 * <pre>
 * class HomaPkt : public HomaPkt_Base
 * {
 *   private:
 *     void copy(const HomaPkt& other) { ... }

 *   public:
 *     HomaPkt(const char *name=NULL, int kind=0) : HomaPkt_Base(name,kind) {}
 *     HomaPkt(const HomaPkt& other) : HomaPkt_Base(other) {copy(other);}
 *     HomaPkt& operator=(const HomaPkt& other) {if (this==&other) return *this; HomaPkt_Base::operator=(other); copy(other); return *this;}
 *     virtual HomaPkt *dup() const {return new HomaPkt(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from HomaPkt_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(HomaPkt);
 * </pre>
 */
class HomaPkt_Base : public ::cPacket
{
  protected:
    inet::L3Address srcAddr_var;
    inet::L3Address destAddr_var;
    uint64_t msgId_var;
    uint32_t priority_var;
    int pktType_var;
    UnschedFields unschedFields_var;
    GrantFields grantFields_var;
    SchedDataFields schedDataFields_var;

  private:
    void copy(const HomaPkt_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const HomaPkt_Base&);
    // make constructors protected to avoid instantiation
    HomaPkt_Base(const char *name=NULL, int kind=0);
    HomaPkt_Base(const HomaPkt_Base& other);
    // make assignment operator protected to force the user override it
    HomaPkt_Base& operator=(const HomaPkt_Base& other);

  public:
    virtual ~HomaPkt_Base();
    virtual HomaPkt_Base *dup() const {throw cRuntimeError("You forgot to manually add a dup() function to class HomaPkt");}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual inet::L3Address& getSrcAddr();
    virtual const inet::L3Address& getSrcAddr() const {return const_cast<HomaPkt_Base*>(this)->getSrcAddr();}
    virtual void setSrcAddr(const inet::L3Address& srcAddr);
    virtual inet::L3Address& getDestAddr();
    virtual const inet::L3Address& getDestAddr() const {return const_cast<HomaPkt_Base*>(this)->getDestAddr();}
    virtual void setDestAddr(const inet::L3Address& destAddr);
    virtual uint64_t getMsgId() const;
    virtual void setMsgId(uint64_t msgId);
    virtual uint32_t getPriority() const;
    virtual void setPriority(uint32_t priority);
    virtual int getPktType() const;
    virtual void setPktType(int pktType);
    virtual UnschedFields& getUnschedFields();
    virtual const UnschedFields& getUnschedFields() const {return const_cast<HomaPkt_Base*>(this)->getUnschedFields();}
    virtual void setUnschedFields(const UnschedFields& unschedFields);
    virtual GrantFields& getGrantFields();
    virtual const GrantFields& getGrantFields() const {return const_cast<HomaPkt_Base*>(this)->getGrantFields();}
    virtual void setGrantFields(const GrantFields& grantFields);
    virtual SchedDataFields& getSchedDataFields();
    virtual const SchedDataFields& getSchedDataFields() const {return const_cast<HomaPkt_Base*>(this)->getSchedDataFields();}
    virtual void setSchedDataFields(const SchedDataFields& schedDataFields);
};


#endif // ifndef _HOMAPKT_M_H_
