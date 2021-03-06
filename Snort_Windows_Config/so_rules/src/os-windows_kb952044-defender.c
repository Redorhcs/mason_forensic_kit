/*
 * Use at your own risk.
 *
 * Copyright (C) 2005-2008 Sourcefire, Inc.
 * 
 * This file is autogenerated via rules2c, by Brian Caswell <bmc@sourcefire.com>

!!! XXX IMPORTANT NOTE 01 XXX !!!
sid 13802 causes an infinite loop if you use the built-in detection function.  This
issue is being looked into.  In the meantime, I have just uncommented the line that
calls the autogenerated detection function and it works fine.

!!! XXX IMPORTANT NOTE 02 XXX !!!
Yes, sid 13802 mixes two big-endian byte_tests in the middle of a bunch of
little-endian operations.  The reason for this is that the magic cookie is
0x010b or 0x020b, which in the packet looks like |0b 01| or |0b 02|. 
Using byte_test on the data, checking for >0x0b00 and < 0x0b03 when
extracting the data as big endian ensures the value is correct.

alert tcp $EXTERNAL_NET $HTTP_PORTS -> $HOME_NET any (msg:"WEB-CLIENT Microsoft malware protection engine denial of service attempt"; flow:to_client,established; flowbits:isset,file.pecompact; content:"|AF 01 02 00 69 EE D1 C2 8B 16 02 32 24 AF 42 73|"; metadata:service http, policy security-ips drop; reference:cve,2008-1437; reference:url,technet.microsoft.com/en-us/security/bulletin/MS08-029; classtype:attempted-dos; sid:13798; rev:1;)

alert tcp $EXTERNAL_NET $HTTP_PORTS -> $HOME_NET any (msg:"WEB-CLIENT Microsoft malware protection engine denial of service attempt"; flow:to_client,established; content:"MZ"; byte_jump:4,58,little,relative; content:"PE|00 00|"; distance:-64; within:4; byte_test:2,>,2816,20,relative,big; byte_test:2,<,2819,20,relative,big; byte_test:4,>,4096,80,relative,little; metadata:service http, policy security-ips drop; reference:cve,2008-1438; reference:url,technet.microsoft.com/en-us/security/bulletin/MS08-029; classtype:attempted-dos; sid:13802; rev:1;)

 */


#include "sf_snort_plugin_api.h"
#include "sf_snort_packet.h"


/* declare detection functions */
int rule13798eval(void *p);
int rule13802eval(void *p);

/* declare rule data structures */
/* precompile the stuff that needs pre-compiled */
/* flow:established, to_client; */
static FlowFlags rule13798flow0 = 
{
    FLOW_ESTABLISHED|FLOW_TO_CLIENT
};

static RuleOption rule13798option0 =
{
    OPTION_TYPE_FLOWFLAGS,
    {
        &rule13798flow0
    }
};
/* flowbits:isset "file.pecompact"; */
static FlowBitsInfo rule13798flowbits1 =
{
    "file.pecompact",
    FLOWBIT_ISSET,
    0,
};

static RuleOption rule13798option1 =
{
    OPTION_TYPE_FLOWBIT,
    {
        &rule13798flowbits1
    }
};
// content:"|AF 01 02 00|i|EE D1 C2 8B 16 02|2|24 AF|Bs"; 
static ContentInfo rule13798content2 = 
{
    (uint8_t *) "|AF 01 02 00|i|EE D1 C2 8B 16 02|2|24 AF|Bs", /* pattern (now in snort content format) */
    0, /* depth */
    0, /* offset */
    CONTENT_BUF_NORMALIZED, /* flags */ // XXX - need to add CONTENT_FAST_PATTERN support
    NULL, /* holder for boyer/moore PTR */
    NULL, /* more holder info - byteform */
    0, /* byteform length */
    0 /* increment length*/
};

static RuleOption rule13798option2 = 
{
    OPTION_TYPE_CONTENT,
    {
        &rule13798content2
    }
};

/* references for sid 13798 */
/* reference: cve "2008-1437"; */
static RuleReference rule13798ref1 = 
{
    "cve", /* type */
    "2008-1437" /* value */
};

/* reference: url "technet.microsoft.com/en-us/security/bulletin/MS08-029"; */
static RuleReference rule13798ref2 = 
{
    "url", /* type */
    "technet.microsoft.com/en-us/security/bulletin/MS08-029" /* value */
};

static RuleReference *rule13798refs[] =
{
    &rule13798ref1,
    &rule13798ref2,
    NULL
};

/* metadata for sid 13798 */
/* metadata:service http, policy security-ips drop; */
static RuleMetaData rule13798service1 = 
{
    "service http"
};


static RuleMetaData rule13798policy1 = 
{
    "policy max-detect-ips drop"
};


static RuleMetaData *rule13798metadata[] =
{
    &rule13798service1,
    &rule13798policy1,
    NULL
};

RuleOption *rule13798options[] =
{
    &rule13798option0,
    &rule13798option1,
    &rule13798option2,
    NULL
};

Rule rule13798 = {
   
   /* rule header, akin to => tcp any any -> any any               */{
       IPPROTO_TCP, /* proto */
       "$EXTERNAL_NET", /* SRCIP     */
       "$HTTP_PORTS", /* SRCPORT   */
       0, /* DIRECTION */
       "$HOME_NET", /* DSTIP     */
       "any", /* DSTPORT   */
   },
   /* metadata */
   { 
       3,  /* genid (HARDCODED!!!) */
       13798, /* sigid */
       8, /* revision */
   
       "attempted-dos", /* classification */
       0,  /* hardcoded priority XXX NOT PROVIDED BY GRAMMAR YET! */
       "OS-WINDOWS Microsoft malware protection engine denial of service attempt",     /* message */
       rule13798refs /* ptr to references */
       ,rule13798metadata
   },
   rule13798options, /* ptr to rule options */
   NULL, // &rule13798eval, /* use the built in detection function */
   0 /* am I initialized yet? */
};
/* precompile the stuff that needs pre-compiled */
/* flow:established, to_client; */
static FlowFlags rule13802flow0 = 
{
    FLOW_ESTABLISHED|FLOW_TO_CLIENT
};

static RuleOption rule13802option0 =
{
    OPTION_TYPE_FLOWFLAGS,
    {
        &rule13802flow0
    }
};
// content:"MZ"; 
static ContentInfo rule13802content1 = 
{
    (uint8_t *) "MZ", /* pattern (now in snort content format) */
    0, /* depth */
    0, /* offset */
    CONTENT_BUF_NORMALIZED, /* flags */ // XXX - need to add CONTENT_FAST_PATTERN support
    NULL, /* holder for boyer/moore PTR */
    NULL, /* more holder info - byteform */
    0, /* byteform length */
    0 /* increment length*/
};

static RuleOption rule13802option1 = 
{
    OPTION_TYPE_CONTENT,
    {
        &rule13802content1
    }
};
/* byte_jump:size 4, offset 58, relative, endian little; */
static ByteData rule13802byte_jump2 = 
{
4, /* size */
    0, /* operator, byte_jump doesn't use operator! */
    0, /* value, byte_jump doesn't use value! */
    58, /* offset */
    0, /* multiplier */
    BYTE_LITTLE_ENDIAN|CONTENT_RELATIVE|CONTENT_BUF_NORMALIZED|EXTRACT_AS_BYTE /* flags */
};

static RuleOption rule13802option2 = 
{
    OPTION_TYPE_BYTE_JUMP,
    {
        &rule13802byte_jump2
    }
};
// content:"PE|00 00|", offset -64, depth 4, relative; 
static ContentInfo rule13802content3 = 
{
    (uint8_t *) "PE|00 00|", /* pattern (now in snort content format) */
    4, /* depth */
    -64, /* offset */
    CONTENT_RELATIVE|CONTENT_BUF_NORMALIZED, /* flags */ // XXX - need to add CONTENT_FAST_PATTERN support
    NULL, /* holder for boyer/moore PTR */
    NULL, /* more holder info - byteform */
    0, /* byteform length */
    0 /* increment length*/
};

static RuleOption rule13802option3 = 
{
    OPTION_TYPE_CONTENT,
    {
        &rule13802content3
    }
};
/* byte_test:size 2, value 2816, operator >, offset 20, relative; */
static ByteData rule13802byte_test4 = 
{
    2, /* size */
    CHECK_GT, /* operator */
    2816, /* value */
    20, /* offset */
    0, /*multiplier */
    BYTE_BIG_ENDIAN|CONTENT_RELATIVE|CONTENT_BUF_NORMALIZED|EXTRACT_AS_BYTE /* flags */
};

static RuleOption rule13802option4 = 
{
    OPTION_TYPE_BYTE_TEST,
    {
        &rule13802byte_test4
    }
};
/* byte_test:size 2, value 2819, operator <, offset 20, relative; */
static ByteData rule13802byte_test5 = 
{
    2, /* size */
    CHECK_LT, /* operator */
    2819, /* value */
    20, /* offset */
    0, /*multiplier */
    BYTE_BIG_ENDIAN|CONTENT_RELATIVE|CONTENT_BUF_NORMALIZED|EXTRACT_AS_BYTE /* flags */
};

static RuleOption rule13802option5 = 
{
    OPTION_TYPE_BYTE_TEST,
    {
        &rule13802byte_test5
    }
};
/* byte_test:size 4, value 4096, operator >, offset 80, relative, endian little; */
static ByteData rule13802byte_test6 = 
{
    4, /* size */
    CHECK_GT, /* operator */
    4096, /* value */
    80, /* offset */
    0, /*multiplier */
    BYTE_LITTLE_ENDIAN|CONTENT_RELATIVE|CONTENT_BUF_NORMALIZED|EXTRACT_AS_BYTE /* flags */
};

static RuleOption rule13802option6 = 
{
    OPTION_TYPE_BYTE_TEST,
    {
        &rule13802byte_test6
    }
};

/* references for sid 13802 */
/* reference: cve "2008-1438"; */
static RuleReference rule13802ref1 = 
{
    "cve", /* type */
    "2008-1438" /* value */
};

/* reference: url "technet.microsoft.com/en-us/security/bulletin/MS08-029"; */
static RuleReference rule13802ref2 = 
{
    "url", /* type */
    "technet.microsoft.com/en-us/security/bulletin/MS08-029" /* value */
};

static RuleReference *rule13802refs[] =
{
    &rule13802ref1,
    &rule13802ref2,
    NULL
};

/* metadata for sid 13802 */
/* metadata:service http, policy security-ips drop; */
static RuleMetaData rule13802service1 = 
{
    "service http"
};


static RuleMetaData rule13802policy1 = 
{
    "policy max-detect-ips drop"
};


static RuleMetaData *rule13802metadata[] =
{
    &rule13802service1,
    &rule13802policy1,
    NULL
};

RuleOption *rule13802options[] =
{
    &rule13802option0,
    &rule13802option1,
    &rule13802option2,
    &rule13802option3,
    &rule13802option4,
    &rule13802option5,
    &rule13802option6,
    NULL
};

Rule rule13802 = {
   
   /* rule header, akin to => tcp any any -> any any               */{
       IPPROTO_TCP, /* proto */
       "$EXTERNAL_NET", /* SRCIP     */
       "$HTTP_PORTS", /* SRCPORT   */
       0, /* DIRECTION */
       "$HOME_NET", /* DSTIP     */
       "any", /* DSTPORT   */
   },
   /* metadata */
   { 
       3,  /* genid (HARDCODED!!!) */
       13802, /* sigid */
       7, /* revision */
   
       "attempted-dos", /* classification */
       0,  /* hardcoded priority XXX NOT PROVIDED BY GRAMMAR YET! */
       "OS-WINDOWS Microsoft malware protection engine denial of service attempt",     /* message */
       rule13802refs /* ptr to references */
       ,rule13802metadata
   },
   rule13802options, /* ptr to rule options */
   &rule13802eval, /* use the built in detection function */
   0 /* am I initialized yet? */
};


/* detection functions */
int rule13798eval(void *p) {
//    const uint8_t *cursor_uri = 0;
//    const uint8_t *cursor_raw = 0;
    const uint8_t *cursor_normal = 0;
    SFSnortPacket *sp = (SFSnortPacket *) p;

    if(sp == NULL)
        return RULE_NOMATCH;

    if(sp->payload == NULL)
        return RULE_NOMATCH;
    
    // flow:established, to_client;
    if (checkFlow(p, rule13798options[0]->option_u.flowFlags) > 0 ) {
        // flowbits:isset "file.pecompact";
        if (processFlowbits(p, rule13798options[1]->option_u.flowBit) > 0) {
                // content:"|AF 01 02 00|i|EE D1 C2 8B 16 02|2|24 AF|Bs";
            if (contentMatch(p, rule13798options[2]->option_u.content, &cursor_normal) > 0) {
                return RULE_MATCH;
            }
        }
    }
    return RULE_NOMATCH;
}
int rule13802eval(void *p) {
    const uint8_t *cursor_uri = 0;
    const uint8_t *cursor_raw = 0;
    const uint8_t *cursor_normal = 0;
    SFSnortPacket *sp = (SFSnortPacket *) p;

    if(sp == NULL)
        return RULE_NOMATCH;

    if(sp->payload == NULL)
        return RULE_NOMATCH;
    
    // flow:established, to_client;
    if (checkFlow(p, rule13802options[0]->option_u.flowFlags) > 0 ) {
        // content:"MZ";
        if (contentMatch(p, rule13802options[1]->option_u.content, &cursor_normal) > 0) {
            // byte_jump:size 4, offset 58, relative, endian little;
            if (byteJump(p, rule13802options[2]->option_u.byte, &cursor_normal) > 0) {
                // content:"PE|00 00|", offset -64, depth 4, relative;
                if (contentMatch(p, rule13802options[3]->option_u.content, &cursor_normal) > 0) {
                    // byte_test:size 2, value 2816, operator >, offset 20, relative;
                    if (byteTest(p, rule13802options[4]->option_u.byte, cursor_normal) > 0) {
                        // byte_test:size 2, value 2819, operator <, offset 20, relative;
                        if (byteTest(p, rule13802options[5]->option_u.byte, cursor_normal) > 0) {
                            // byte_test:size 4, value 4096, operator >, offset 80, relative, endian little;
                            if (byteTest(p, rule13802options[6]->option_u.byte, cursor_normal) > 0) {
                                return RULE_MATCH;
                            }
                        }
                    }
                }
            }
        }
    }
    return RULE_NOMATCH;
}

/*
Rule *rules[] = {
    &rule13798,
    &rule13802,
    NULL
};
*/
