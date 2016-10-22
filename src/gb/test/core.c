/* Copyright (c) 2013-2016 Jeffrey Pfau
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#include "util/test/suite.h"

#include "core/core.h"
#include "gb/core.h"

M_TEST_DEFINE(create) {
	struct mCore* core = GBCoreCreate();
	assert_non_null(core);
	assert_true(core->init(core));
	core->deinit(core);
}

M_TEST_DEFINE(platform) {
	struct mCore* core = GBCoreCreate();
	assert_non_null(core);
	assert_true(core->platform(core) == PLATFORM_GB);
	assert_true(core->init(core));
	core->deinit(core);
}

M_TEST_DEFINE(reset) {
	struct mCore* core = GBCoreCreate();
	assert_non_null(core);
	assert_true(core->init(core));
	core->reset(core);
	core->deinit(core);
}

M_TEST_DEFINE(loadNullROM) {
	struct mCore* core = GBCoreCreate();
	assert_non_null(core);
	assert_true(core->init(core));
	assert_false(core->loadROM(core, NULL));
	core->reset(core);
	core->deinit(core);
}

M_TEST_SUITE_DEFINE(GBCore,
	cmocka_unit_test(create),
	cmocka_unit_test(platform),
	cmocka_unit_test(reset),
	cmocka_unit_test(loadNullROM))
