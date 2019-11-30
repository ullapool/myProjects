<?php
require __DIR__.'./../src/Database.php';
use Database;
use PHPUnit\Framework\TestCase;

class DatabaseTest extends TestCase
{

    public function testConnectDatabase()
    {
        $connection = Database::GetDatabaseInstance("Server", "Oliver","1234","Test","3000");
        $connection2 = Database::GetDatabaseInstance("Server", "Oliver","1234","Test","3000");
        $this->assertSame($connection,$connection2);
        $this->assertEquals(4,2+2);
    }
}
