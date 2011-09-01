PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE "names" (
"id" TEXT,
"priority" INTEGER NOT NULL DEFAULT '0',
"username" TEXT,
"full_name" TEXT ,
"avatar_url" TEXT,
"updated_at" INTEGER);
CREATE TABLE "hashtags" (
"id" TEXT,
"priority" INTEGER NOT NULL DEFAULT '0',
"hashtag" TEXT ,
"description" TEXT,
"updated_at" INTEGER);
CREATE TABLE "places" (
"id" TEXT DEFAULT NULL,
"priority" INTEGER NOT NULL DEFAULT '0',
"name" TEXT DEFAULT NULL,
"place_type" INTEGER,
"address" TEXT DEFAULT NULL,
"latitude" REAL DEFAULT NULL,
"longitude" REAL DEFAULT NULL,
"updated_at" INTEGER);
CREATE UNIQUE INDEX "name_primary" ON "names" ("id","priority");
CREATE UNIQUE INDEX "hashtag_primary" ON "hashtags" ("id","priority");
CREATE UNIQUE INDEX "place_primary" ON "places" ("id","priority");
CREATE INDEX "full_name_index" ON "names" ("full_name");
CREATE INDEX "name_index" ON "places" ("name");
CREATE INDEX "place_type_index" ON "places" ("place_type");
CREATE INDEX "address_index" ON "places" ("address");
CREATE INDEX "latitude_index" ON "places" ("latitude");
CREATE INDEX "longitude_index" ON "places" ("longitude");
CREATE INDEX "name_timestamp_index" ON "names" ("updated_at");
CREATE INDEX "place_timestamp_index" ON "places" ("updated_at");
CREATE INDEX "hashtag_timestamp_index" ON "hashtags" ("updated_at");
COMMIT;