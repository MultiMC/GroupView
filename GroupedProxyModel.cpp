#include "GroupedProxyModel.h"

#include "GroupView.h"

GroupedProxyModel::GroupedProxyModel(QObject *parent) : QSortFilterProxyModel(parent)
{
}

bool GroupedProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
	const QString leftCategory = left.data(GroupViewRoles::GroupRole).toString();
	const QString rightCategory = right.data(GroupViewRoles::GroupRole).toString();
	if (leftCategory == rightCategory)
	{
		return left.row() < right.row();
	}
	else
	{
		return leftCategory < rightCategory;
	}
}
