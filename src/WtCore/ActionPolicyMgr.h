/*!
 * \file ActionPolicyMgr.h
 * \project	WonderTrader
 *
 * \author Wesley
 * \date 2020/03/30
 * 
 * \brief 
 */
#pragma once
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <string.h>

#include "../Share/WTSMarcos.h"


NS_OTP_BEGIN
class WTSVariant;

typedef enum tagActionType
{
	AT_Unknown = 8888,
	AT_Open = 9999,	//����
	AT_Close,		//ƽ��
	AT_CloseToday,	//ƽ��
	AT_CloseYestoday	//ƽ��
} ActionType;

typedef struct _ActionRule
{
	ActionType	_atype;
	uint32_t	_limit;
	uint32_t	_limit_l;
	uint32_t	_limit_s;

	_ActionRule()
	{
		memset(this, 0, sizeof(_ActionRule));
	}
} ActionRule;

typedef std::vector<ActionRule>	ActionRuleGroup;

class ActionPolicyMgr
{
public:
	ActionPolicyMgr();
	~ActionPolicyMgr();

public:
	bool init(const char* filename);

	const ActionRuleGroup& getActionRules(const char* pid);

private:
	typedef std::unordered_map<std::string, ActionRuleGroup> RulesMap;
	RulesMap	_rules;	//�����

	std::unordered_map<std::string, std::string> _comm_rule_map;	//Ʒ�ֹ���ӳ��
};

NS_OTP_END