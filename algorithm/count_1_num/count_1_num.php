<?php
	/**
	 *	统计1的个数
	 */
	function fun($n)
	{
		$str = "";
		for ($i = 1; $i <= $n; $i++)
		{
			$str .= $i;
		}
		$str2 = str_replace("1", "", $str);
		return strlen($str) - strlen($str2);
	}